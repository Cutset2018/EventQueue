#include "EventQueue.h"
#include <thread>
#include <chrono>

int EventQueue::scheduleSleep(double duration, double delay = 0){
    std::this_thread::sleep_for(std::chrono::milliseconds(delay*1000));
    
    std::this_thread::sleep_for(std::chrono::milliseconds(duration*1000));
}
int EventQueue::scheduleSleepPeriodically(double duration, double period){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(duration*1000));
        std::this_thread::sleep_for(std::chrono::milliseconds(period*1000));
    }
}
int EventQueue::scheduleTask(Task *task, int priority, double delay = 0){
    std::this_thread::sleep_for(std::chrono::milliseconds(delay*1000));
    addTask(*task,priority);
}
int EventQueue::scheduleTaskPeriodically(Task *task, int priority, double period){
    while(true){
        addTask(*task,priority);
        std::this_thread::sleep_for(std::chrono::milliseconds(period*1000));
    }
    
}



