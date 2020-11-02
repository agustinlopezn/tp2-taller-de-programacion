#include <mutex>
#include <list>
#include <iostream>
#include <string>

class Results {
 private:
    std::list <std::string> results;
    std::mutex m;
 public:
    Results();
    void addResult(std::string fileName, bool isCyclic, bool unusedInstr);
    void print();
    ~Results();
};
