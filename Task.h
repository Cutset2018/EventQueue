#ifndef Task_H
#define Task_H

class Task {
    public:
        Task(double data) {val = data;};
        virtual void execute(double currentTime) = 0;

    protected:
        double getData() {return val;};

    private:
        double val;

};

#endif // Task_H
