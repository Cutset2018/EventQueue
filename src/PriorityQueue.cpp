#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity) {
    heap = new Node[capacity];
    cap = capacity;
    numNodes = 0;
}
