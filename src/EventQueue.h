#ifndef EventQueue_H
#define EventQueue_H

#include "PriorityQueue.h"

class EventQueue : public PriorityQueue {
    public:
        EventQueue(int capacity) : PriorityQueue(capacity) {};
        bool addTaskPeriodic(Task *task, int priority);
    
    protected:

    private:

};

#endif
