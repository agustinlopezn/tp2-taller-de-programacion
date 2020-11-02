#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <mutex>
#include "thread.h"
#include "files.h"

class FileParser {
 private:
    int line;
    std::ifstream file;
    // std::map<std::string, std::vector<std::string>> instructions;
    std::string actualFile;
    Files &files;
    std::mutex m;


 public:
    FileParser(const char *filesNames[], Files &files);
    bool areFilesToProcces();
    std::string proccessedFile();
    void getInstructions(std::string &buffer, std::map<std::string, std::vector<std::string>> &instructions);
    // void run();
    ~FileParser();
};
