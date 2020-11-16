#include "files.h"
#include "lock.h"

Files::Files(const char *files[]) {
    i = 0;
    this->files = files;
}

bool Files::getFileIfExists(std::string &fileName) {
    Lock l(m);
    if (files[i])
        ++i;
    else
        return false;
    fileName = this->files[i-1];
    return true;
}

Files::~Files() {
    i = 0;
}
