#ifndef __THREAD_H
#define __THREAD_H

#include <thread>
#include <utility>

class Thread {
 private:
    std::thread thread;

 public:
    // Constructor and destructor
    Thread();
    virtual ~Thread();

    // Method that has to be implemented by the inherited classes
    virtual void run() = 0;

    // Starts the thread execution
    void start();

    // Makes the thread destroyable when its completes all its operations
    void join();

    // Disalows construction by copy
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;

    // Disalows construction by movement
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
};

#endif  // THREAD_H_
