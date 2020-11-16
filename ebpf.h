#ifndef __EBPF_H
#define __EBPF_H

#include <string>
#include <map>
#include <vector>
#include "digraph.h"
#include "file_parser.h"
#include "results.h"

class eBPF : public Thread{
 private:
    Results &results;
    Files &files;
    std::string proccessedFile;
 public:
    // Constructor that receives the shared resources
    // and stores it as members of the class
    eBPF(Results &results, Files &files);

    // Iterates all the files, parses its lines, adds the information
    // to a graph and puts the result in results
    void run() override;

    ~eBPF();
};

#endif  // EBPF_H_
