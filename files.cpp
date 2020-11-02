#include "files.h"
#include <iostream>
#include "lock.h"

Files::Files(const char *files[]) {
    // size_t i = 0;
    // while (files[i]) {
    //    std::ifstream file;
    //    (file).open(files[i]);
    //    if (!file) {
    //        throw "Error opening files";
    //    }
    //    this->files.push_back(file);
    //    this->filesNames.push_back(files[i]);
    //    ++i;
    // }
    i = 0;
    this->files = files;
}

bool Files::areFilesToProcces() {
    Lock l(m);
    // return !this->files.empty();
    return this->files[i];
}

std::string Files::actualFile() {
    Lock l(m);
    // return this->filesNames.front();
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
    // this->filesNames.pop_front();
    // delete(this->files.front());
    // file = this->files.front();
    // this->files.pop_front();
    // this->m.unlock();
}

Files::~Files() {
    // i = 0;
}
