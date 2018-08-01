#ifndef PriorityQueue_H
#define PriorityQueue_H

class PriorityQueue {
    typedef void (*funcptr)();
    public:
        struct Node {
            funcptr function;
            int priority;
        };

        PriorityQueue(int capacity);
        bool addTask(funcptr function, int priority);
        int size() {return numNodes;};
        bool empty() {return numNodes == 0;};
        bool full() {return numNodes == cap;};
        Node getFirst();
        void extractFirst();        
    
    protected:

    private:
        int cap;
        int numNodes;
        Node *heap;

        int parent(int i) {return (i - 1) / 2;};
        int left(int i) {return 2 * i + 1;};
        int right(int i) {return 2 * i + 2;};
        void swap(int a, int b);
        void heapify(int root);

};

#endif // PriorityQueue_H
