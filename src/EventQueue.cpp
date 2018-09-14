#include "EventQueue.h"

#include <thread>
#include <chrono>
using namespace std::this_thread;     // sleep_for, sleep_until
using std::chrono::system_clock;
using namespace std::chrono;

// void EventQueue::scheduleSleep(int duration, int delay){
//     sleep_for(seconds(delay)); 
//     sleep_for(seconds(duration));
// }
// void EventQueue::scheduleSleepPeriodically(int duration, int period){
//     while(true){
//         sleep_for(seconds(duration));
//         sleep_for(seconds(period));
//         printHeap();
//     }
// }
// void EventQueue::scheduleTask(Task *task, int priority, int delay){
//     sleep_for(seconds(delay));
//     addTask(task,priority);
//     printHeap();
// }
// void EventQueue::scheduleTaskPeriodically(Task *task, int priority, int period){
//     while(true){
//         addTask(task,priority);
//         sleep_for(seconds(period));
//         printHeap();
//     }
    
// }





