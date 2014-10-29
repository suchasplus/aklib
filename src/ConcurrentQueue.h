#ifndef AK_CONCURRENTQUEUE_H
#define AK_CONCURRENTQUEUE_H

/**
 * Provide C++11 compatiable edition
 * refer: https://www.justsoftwaresolutions.co.uk/threading/implementing-a-thread-safe-queue-using-condition-variables.html
 *
 * Using std::unique_lock instead of boost::mutex::scoped_lock
 * refer: http://stackoverflow.com/questions/22676871/boost-scoped-lock-replacement-in-c11
 *
 */

#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <ak.h>

namespace ak {
template<typename Data>  
class ConcurrentQueue
{  
private:  
    std::queue<Data> _msg_queue ;
    mutable std::mutex _mutex ;
    std::condition_variable _condition_variable ; // Message current queue.
    bool _is_running ;
    uint32_t _max_queue_size ;
public:
    ~ConcurrentQueue() {
    }

    ConcurrentQueue(uint32_t max_queue_size) : _is_running(true),
                 _max_queue_size(max_queue_size) {}
private:
    DISALLOW_COPY_AND_ASSIGN(ConcurrentQueue) ;

public:  
    int push(Data const& data)  
    {  
        std::unique_lock<std::mutex> lock(_mutex) ;  
        if (_msg_queue.size() >= _max_queue_size) {
            return -1;
        }
        _msg_queue.push(data) ;
        // Out of range max queue size.
        lock.unlock() ;
        _condition_variable.notify_one() ;  
        return 0 ;
    }

    bool empty() const 
    {  
        std::unique_lock<std::mutex> lock(_mutex) ;  
        return _msg_queue.empty() ;  
    }

    bool try_pop(Data& popped_value)  
    {  
        std::unique_lock<std::mutex> lock(_mutex) ;
        if(_msg_queue.empty())  
        {  
            return false;  
        }  

        popped_value = _msg_queue.front();  
        _msg_queue.pop();  
        return true;  
    }

    void wait_and_pop(Data& popped_value)  
    {  
        std::unique_lock<std::mutex> lock(_mutex) ;  
        while(_msg_queue.empty())  
        { 
            if ( ! _is_running ) {
                return ;
            }
            _condition_variable.wait(lock) ;
            if ( ! _is_running ) {
                return ;
            }
        }  
        popped_value = _msg_queue.front() ; 
        _msg_queue.pop() ;  
    }

    int size() const {
        std::unique_lock<std::mutex> lock(_mutex) ;
        return _msg_queue.size() ;
    }

    void stop() {
        _is_running = false;
        _condition_variable.notify_all();
    }
};

} // end namespace ak
#endif //end AK_CONCURRENTQUEUE_H
