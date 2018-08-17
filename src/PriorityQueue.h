#ifndef PriorityQueue_H
#define PriorityQueue_H

#include "Task.h"

class PriorityQueue {
    // Typedef for functions with no parameters or return type.
    public:
        static const int MAX_QUEUE_SIZE = 128;
        static const int MIN_USER_PRIORITY = 3;

        PriorityQueue(int capacity);
        /**
         * Affs a task to the queue with a given priority.
         * Priorities 1 and 2 are reserved for the system and will be automatically adjusted to 3.
         * Returns whether the task was successfully added.
         */
        int addTask(Task *task, int priority); // done
        /**
         * Returns the number of tasks in the queue.
         */
        int size() {return numNodes;};
        /**
         * Returns whether the queue is empty.
         */
        bool empty() {return numNodes == 0;};
        /**
         * Returns whether the queue is filled to capacity.
         */
        bool full() {return numNodes == cap;};

        
        
        Task* extractFirst(); // done
        int getFirstTaskPriority(); // done
        Task* getFirstTask(); // done
        void deleteTask(int index);
        void clearQueue(); // Done

    protected:
        /**
         * Adds a task to the queue, allowing the use of any priority.
         * Intended for system use only.
         * Returns whether the task was successfully added.
         */
        int addTaskInternal(Task *task, int priority); // done

    private:
        // Internal structure to store tasks together with their priority in the queue
        struct Node {
            Task *task; 
            int priority;
            int id;
        };
        struct DeleteNode {
            bool used = false;
            bool deleted = true;
            bool taskPending = false;
        };

        int cap;
        int numNodes;
        Node heap[MAX_QUEUE_SIZE * 2];
        DeleteNode taskStatus[MAX_QUEUE_SIZE];
        int j=0;
        // Counter used to assign a unique id to each task
        int idCounter = 0;

        void addNode(Node node);
        int findAvailableId();
        int parent(int i) {return (i - 1) / 2;};
        int left(int i) {return 2 * i + 1;};
        int right(int i) {return 2 * i + 2;};
        void swap(int a, int b); // done
        void heapify(int root);

};

#endif // PriorityQueue_H
