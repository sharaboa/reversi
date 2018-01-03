//
// Created by sahar on 01/01/18.
//

#ifndef SERVER_THREADLIST_H
#define SERVER_THREADLIST_H


#include <sys/types.h>
#include <vector>
using namespace std;
class ThreadList {
public:
/**
 * creating a singelton pattern class to keep a list of all the current oppened threads
 * @return the class itself if exist otherwise create a new one
 */
    static ThreadList *getInstance();
    /**
     * the opened thread vector
     * @return
     */
    vector<pthread_t> getThreadList() const;
    /**
     * adding a new thread id to the vector
     * @param pthread the added pthread id
     */
    void addThread(pthread_t pthread);
private:
    vector<pthread_t> threadList;
    ThreadList(): threadList() {}; // Private c'tor
    ThreadList(const ThreadList &other); // Private copy c'tor
    ~ThreadList() {};
    static ThreadList *instance;
    static pthread_mutex_t lock1;

};


#endif //SERVER_THREADLIST_H