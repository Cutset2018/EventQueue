#include <iostream>
#include "src/PriorityQueue.h"
#include "src/EventQueue.h"
#include "src/Task.h"
#include "src/TestTask.h"


using namespace std;

int main() {
    PriorityQueue pQueue(128);
    //EventQueue eQueue(128);
    TestTask foo(0);
    Task *task = &foo;
    cout << "Create a heap.\n";
    pQueue.addTask(task,3);
    pQueue.addTask(task,645);
    pQueue.addTask(task,5);
    pQueue.addTask(task,67);
    pQueue.addTask(task,23);
    pQueue.addTask(task, 52);
    pQueue.addTask(task, 4);
    pQueue.addTask(task, 6);
    pQueue.addTask(task, 75);
    pQueue.addTask(task, 436);
    pQueue.addTask(task, 43);
    pQueue.addTask(task, 8);
    pQueue.addTask(task, 9);
    pQueue.addTask(task, 11);
    pQueue.addTask(task, 10);
    pQueue.addTask(task, 45);
    pQueue.addTask(task, 23);
    pQueue.addTask(task, 12);
    pQueue.addTask(task, 15);
    pQueue.addTask(task, 454);
    pQueue.addTask(task, 124);
    pQueue.printHeap();
    cout << "Extract first.\n";
    pQueue.extractFirst();
    pQueue.printHeap();
    pQueue.getFirstTask();
    pQueue.getFirstTaskPriority();
    cout << "Delete some tasks.\n";
    pQueue.deleteTask(11);
    pQueue.deleteTask(12);
    pQueue.deleteTask(14);
    pQueue.deleteTask(17);
    pQueue.printHeap();
    cout << "After extracting 3 nodes, the root is a deleted task. The two nodes that follow it are also deleted and are removed.\n";
    pQueue.extractFirst();
    pQueue.extractFirst();
    pQueue.extractFirst();
    pQueue.printHeap();
    cout << "Delete more tasks.\n";
    pQueue.deleteTask(16);
    pQueue.deleteTask(3);
    pQueue.deleteTask(5);
    pQueue.printHeap();
    cout << pQueue.numTasksPendingDeletion() << endl;
    cout << "Purge deleted tasks.\n";
    pQueue.purgeDeletedTasks();
    pQueue.printHeap();
    cout << "Clear queue.\n";
    pQueue.clearQueue();
    pQueue.printHeap();
    cout << "Create a new heap.\n";
    pQueue.addTask(task, 3);
    pQueue.addTask(task, 4);
    pQueue.addTask(task, 5);
    pQueue.addTask(task, 6);
    pQueue.addTask(task, 7);
    pQueue.printHeap();
    cout << "Delete a task and extract a node, allowing ids 0 and 1 to be reused.\n";
    pQueue.deleteTask(1);
    pQueue.extractFirst();
    pQueue.addTask(task, 8);
    pQueue.addTask(task, 9);
    pQueue.printHeap();






    return 0;
}
