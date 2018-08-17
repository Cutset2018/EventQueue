#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int capacity) {
    heap = new Node[capacity];
    cap = capacity;
    numNodes = 0;
}

bool PriorityQueue::addTask(Task *task, int priority) {
    int adjustedPriority = priority;
    if(adjustedPriority < 3) adjustedPriority = 3;
    return addTaskInternal(task, adjustedPriority);
}

bool PriorityQueue::addTaskInternal(Task *task, int priority){
    if (numNodes == cap) {
        std::cout << "Heap is full. Task not added.";
        return false;
    }
    int adjustedPriority = priority;
    if(adjustedPriority < 1) adjustedPriority = 1;
    numNodes++;
    int i = numNodes - 1;
    heap[i].task = task;
    heap[i].priority = adjustedPriority;
    while (i > 0 && heap[parent(i)].priority > heap[i].priority) {
       swap(i, parent(i));
       i = parent(i);
    }                            

    return true;
}

Task* PriorityQueue::getFirstTask() {
    if(empty()) return nullptr;                
    return heap[0].task;
}
int PriorityQueue::getFirstTaskPriority() {
    if(empty()) return 0;
    return heap[0].priority;
}
Task* PriorityQueue::extractFirst() {
    if(empty()) return nullptr;
    Task *task = getFirstTask();
    --numNodes;
    if(numNodes > 0) {
        heap[0] = heap[numNodes];
        heapify(0);
    }
    return task;
    
}

void PriorityQueue::deleteTask(int index){
    if(empty()){
        std::cout<<"already empty";
        return;
    }
    else{
        for(int i=0;i<numNodes;i++){
            temp[i].task=heap[i].task;
            temp[i].priority=heap[i].priority;
        }
        delete heap;
        numNodes--;
        heap = new Node[numNodes];
        
        
        while(j < numNodes){
            if(j==index)
                continue;
            heap[j].task=temp[j].task;
            heap[j].priority=temp[j].priority;    
            j++;
        }

    }
    Node temp;
}

void PriorityQueue::clearQueue() {
    delete heap;
    heap = new Node[cap];
    numNodes = 0;

}

void PriorityQueue::swap(int a, int b) {
    Node tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;    
}

void PriorityQueue::heapify(int root){  
    int l = left(root), r = right(root), low = root;
    if (l < numNodes && heap[l].priority < heap[low].priority)
        low = l;
    if (r < numNodes && heap[r].priority < heap[low].priority)
        low = r;
    if (low != root) {
        swap(root, low);
        heapify(low);
    }
}
/*basically, when the user adds a task, it is converted to a node, which stores the function (task)
and its priority. priority (accessed via heap[index].priority) is used as the sorting criteria
of the heap (basically the key value from the tutorials). heap[index].function is only used
when the task itself is needed (i.e. when it is extracted or run)*/

// also, i split add task into add task and add task internal
// since Boyang wanted us to reserve the highest priorities for the system, i made addTask increase 
// priority 1 or 2 to 3. addTaskInternal is protected and allows priority 1 and 2.
