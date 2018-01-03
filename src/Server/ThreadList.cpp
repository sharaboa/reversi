//
// Created by sahar on 01/01/18.
//

#include <pthread.h>
#include "ThreadList.h"



ThreadList *ThreadList::instance = 0;
pthread_mutex_t ThreadList::lock1;
ThreadList *ThreadList::getInstance(){
    if (instance == 0)
    {
        pthread_mutex_lock(&lock1);
        if (instance ==0) {
            instance = new ThreadList;

        }
        pthread_mutex_unlock(&lock1);
    }
    return instance;
}

vector<pthread_t> ThreadList::getThreadList() const {
    return threadList;
}

void ThreadList::addThread(pthread_t pthread) {
    threadList.push_back(pthread);
}