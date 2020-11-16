#ifndef __RESULTS_H
#define __RESULTS_H

#include <mutex>
#include <list>
#include <iostream>
#include <string>

class Results {
 private:
    std::list <std::string> results;
    std::mutex m;
 public:
    // Constructor and destructor
    Results();
    ~Results();

    // Adds the result of a file and prepares the output based on the
    // booleans values
    void addResult(const std::string &fileName,
                bool isCyclic, bool unusedInstr);

    // Prints all the results to the standard output
    void print();
};

#endif  // RESULTS_H_
