#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int capacity) {
    cap = capacity;
    numNodes = 0;
    for(int i = 0; i < cap; i++) {
        pendingDeletion[i] = false;
        freeIds[i] = i;
    }
    for(int i = cap; i < MAX_QUEUE_SIZE; i++) {
        freeIds[i] = -1;
    }
}

int PriorityQueue::addTask(Task *task, int priority) {
    int adjustedPriority = priority;
    if(adjustedPriority < MIN_USER_PRIORITY) {
        adjustedPriority = MIN_USER_PRIORITY;
    }
    return addTaskInternal(task, adjustedPriority);
}

int PriorityQueue::addTaskInternal(Task *task, int priority){
    if (numNodes == cap) {
        std::cout << "Heap is full. Task not added.";
        return 0;
    }
    int adjustedPriority = priority;
    if(adjustedPriority < 1) adjustedPriority = 1;
    int id = reserveNewId();
    ++numNodes;
    int i = numNodes - 1;
    heap[i].id = id;
    heap[i].task = task;
    heap[i].priority = adjustedPriority;
    int i = numNodes - 1;
    while (i > 0 && heap[parent(i)].priority > heap[i].priority) {
       swap(i, parent(i));
       i = parent(i);
    }
    
    return heap[i].id;
}

Task* PriorityQueue::getFirstTask() {
    if(empty()){
        return nullptr;
    }
    return heap[0].task;
}
int PriorityQueue::getFirstTaskPriority() {
    if(empty()){
        return 0;
    } 
    return heap[0].priority;
}


Task* PriorityQueue::extractFirst() {
    if(empty()) return nullptr;
    Task *task = getFirstTask();
    do {
        popRoot();
    }
    while(pendingDeletion[heap[0].id]);

    return task;
}

void PriorityQueue::popRoot() {
    pendingDeletion[heap[0].id] = false;
    releaseId(heap[0].id);
    --numNodes;
    if(!empty()) {
        heap[0] = heap[numNodes];
        heapify(0);
    }
}


void PriorityQueue::deleteTask(int id){
    if(empty()){
        std::cout<<"already empty";
        return;
    }
    else if(heap[0].id == id) {
        popRoot();
    }
    else{
        pendingDeletion[id]=true;
    }
}

int PriorityQueue::reserveNewId(){
    int freeId = freeIds[cap - 1 - numNodes];
    freeIds[cap - 1 - numNodes] = 0;
    return freeId;
}

void PriorityQueue::releaseId(int id){
    freeIds[cap-numNodes] = id;
}

void PriorityQueue::clearQueue() {
    numNodes = 0;
}

void PriorityQueue::swap(int a, int b) {
    Node tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;    
}



void PriorityQueue::heapify(int root) {
    int l, r, low;
    while(true) {
        l = left(root), r = right(root), low = root;
        if (l < numNodes && heap[l].priority < heap[low].priority) {
            low = l;
        }
        if (r < numNodes && heap[r].priority < heap[low].priority) {
            low = r;
        }
        if (low != root) {
            swap(root, low);
            root = low;
        }
        else return;
    }
}
/*basically, when the user adds a task, it is converted to a node, which stores the function (task)
and its priority. priority (accessed via heap[index].priority) is used as the sorting criteria
of the heap (basically the key value from the tutorials). heap[index].function is only used
when the task itself is needed (i.e. when it is extracted or run)*/

// also, i split add task into add task and add task internal
// since Boyang wanted us to reserve the highest priorities for the system, i made addTask increase 
// priority 1 or 2 to 3. addTaskInternal is protected and allows priority 1 and 2.
