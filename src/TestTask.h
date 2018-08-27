#ifndef TestTask_H
#define TestTask_H

#include "Task.h"

class TestTask : public Task {
    public:
        TestTask(double data) : Task(data) {};
        void execute(double currentTime) {return;};

    protected:

    private:

};

#endif // TestTask_H
