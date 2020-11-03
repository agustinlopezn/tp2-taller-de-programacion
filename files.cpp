#include "files.h"
#include "lock.h"

Files::Files(const char *files[]) {
    i = 0;
    this->files = files;
}

bool Files::areFilesToProcces() {
    Lock l(m);
    return this->files[i];
}

std::string Files::actualFile() {
    Lock l(m);
    return this->files[i-1];
}

std::string Files::getFile(std::ifstream &file) {
    Lock l(m);
    if (files[i]) {
        file.open(files[i]);
        filesNames.push_back(files[i]);
        ++i;
    }
    return this->files[i-1];
}

Files::~Files() {
    i = 0;
}
