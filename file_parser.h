#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <map>
#include <algorithm>

/* Excepciones */
struct FileParserException : std::exception {
    const char *what();
};

class FileParser {
 private:
    int line;
    std::ifstream file;
 public:
    explicit FileParser(const std::string file_name);
    void getInstructions(std::map<std::string, std::vector<std::string>> &instructions, std::string &buffer);
    bool getInstruction(std::string &buffer);
    ~FileParser();
};
