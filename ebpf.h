#include <string>
#include <map>
#include <vector>
#include "digraph.h"
#include "file_parser.h"
#include "results.h"

class eBPF : public Thread{
 private:
    const char **filesNames;
    Results &results;
    Files &files;
 public:
    explicit eBPF(const char *filesNames[], Results &results, Files &files);
    void run() override;
    std::ifstream getFile();
    ~eBPF();
};
