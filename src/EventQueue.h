#ifndef EventQueue_H
#define EventQueue_H

#include "PriorityQueue.h"

class EventQueue : public PriorityQueue {
    public:
        EventQueue(int capacity) : PriorityQueue(capacity) {};
        void scheduleTask(Task *task, int priority, int delay = 0);
        void scheduleTaskPeriodically(Task *task, int priority, int period);
        void scheduleSleep(int duration, int delay = 0);
        void scheduleSleepPeriodically(int duration, int period);
        void start();
        
    protected:

    private:
        using PriorityQueue::addTask;


};

#endif
