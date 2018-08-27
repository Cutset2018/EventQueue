#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int capacity) {
    cap = capacity;
    numNodes = 0;
    for(int i = 0; i < cap; i++) {
        pendingDeletion[i] = false;
        freeIds[i] = cap - i - 1;
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
    popRoot();
    while(pendingDeletion[heap[0].id]) {
        popRoot();
        --numPendingDeletion;
    }

    return task;
}

void PriorityQueue::popRoot() {
    if(empty()) return;
    pendingDeletion[heap[0].id] = false;
    releaseId(heap[0].id);
    --numNodes;
    if(!empty()) {
        heap[0] = heap[numNodes];
        heapify(0);
    }
}

void PriorityQueue::deleteTask(int id){
    if(empty() || id < 0 || id > cap - 1){
        std::cout<<"already empty";
        return;
    }
    else if(heap[0].id == id) {
        extractFirst();
    }
    else {
        pendingDeletion[id]=true;
        ++numPendingDeletion;
    }
}

void PriorityQueue::purgeDeletedTasks() {
    for(int i = 0; i < numNodes && numPendingDeletion > 0; i++) {
        if(pendingDeletion[heap[i].id]) {
            int j = i;
            while(j > 0) {
                swap(j, parent(j));
                j = parent(j);
            }
            popRoot();
            --numPendingDeletion;
            --i;
        }
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
    numPendingDeletion = 0;
    for(int i = 0; i < cap; i++) {
        pendingDeletion[i] = false;
        freeIds[i] = cap - i - 1;
    }
    for(int i = cap; i < MAX_QUEUE_SIZE; i++) {
        freeIds[i] = -1;
    }
}
void PriorityQueue::printHeap(){
    std::cout << "--------------------------------------------------\n";
    std::cout << "Size: " << size() << ", Capacity: " << cap << "\n\n";
    printFromNode(0, 0);
    std::cout << "--------------------------------------------------\n";

}
void PriorityQueue::printFromNode(int index, int indent = 0) {
    if(index < numNodes) {
        if(indent > 0) {
            for(int i = 0; i < indent; i++) {
                if(i%2==0){
                    std::cout << '|';
                }
                std::cout << '-';
            }
        }
        std::cout << heap[index].id << " (" << heap[index].priority << ")";
        if(pendingDeletion[heap[index].id]) {
            std::cout << " [DELETED]";
        }
        std::cout << "\n";
        if(left(index) < numNodes) {
            printFromNode(left(index), indent + 2);
        }
        if(right(index) < numNodes) {
            printFromNode(right(index), indent + 2);
        }
    }
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
