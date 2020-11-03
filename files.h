#ifndef __FILES_H
#define __FILES_H
#include <list>
#include <string>
#include <mutex>
#include <fstream>

class Files {
 private:
    const char **files;
    size_t i;
    std::list <std::string> filesNames;
    std::mutex m;
 public:
    explicit Files(const char *files[]);
    std::string actualFile();
    bool areFilesToProcces();
    std::string getFile(std::ifstream &file);
    ~Files();
};

#endif  // FILES_H_
