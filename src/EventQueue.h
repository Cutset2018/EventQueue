#ifndef EventQueue_H
#define EventQueue_H

#include "PriorityQueue.h"

class EventQueue : public PriorityQueue {
    public:
        EventQueue(int capacity) : PriorityQueue(capacity) {};
        int scheduleTask(Task *task, int priority, double delay = 0);
        void scheduleTaskPeriodically(Task *task, int priority, double period);
        void scheduleSleep(double duration, double delay = 0);
        void scheduleSleepPeriodically(double duration, double period);
        void start();
    protected:

    private:
        using PriorityQueue::addTask;


};

#endif
