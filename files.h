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
    std::mutex m;
 public:
    // Stores files in the atributes of the class
    explicit Files(const char *files[]);

    // Returns true if there is a valid file and modifies fileName, returns
    // false in other case and doesnt modifies the fileName
    bool getFileIfExists(std::string &fileName);

    ~Files();
};

#endif  // FILES_H_
