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
 public:
    eBPF(Results &results, Files &files);
    void run() override;
    ~eBPF();
};

#endif  // EBPF_H_
