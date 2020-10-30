#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Instruction {
 private:
    int line;
    std::string opt;
    std::string label;
 public:
    explicit Instruction(const std::string &buffer);
    ~Instruction();
};
