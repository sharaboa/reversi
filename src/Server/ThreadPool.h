//
// Created by or on 21/01/18.
//

#ifndef REVERSI_THREADPOOL_H
#define REVERSI_THREADPOOL_H


#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
public:
    /**
     * constructor
     * @param threadsNum num of max threads running
     */
    ThreadPool(int threadsNum);
    /**
     * adding task
     * @param task
     */
    void addTask(Task* task);
    /**
     * pthread mutex destroy
     */
    void terminate();
    /**
     * destructor
     */
    virtual~ThreadPool();
private:
    queue<Task *> tasksQueue;
    pthread_t * threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);
};


#endif //REVERSI_THREADPOOL_H
