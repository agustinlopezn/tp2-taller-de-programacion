#include <vector>
#include "thread.h"
#include "ebpf.h"

#define THR_QNT_POS 1
#define FILES_INITIAL_POS 2
#define MIN_PARAMS 3

int main(int argc, const char *argv[]) {
    if (argc < MIN_PARAMS) {
        std::cerr << "Not enough paramateres" << std::endl;
        return 0;
    }
    std::vector<eBPF*> threads;
    Results results;
    Files files(&argv[FILES_INITIAL_POS]);
    int threads_num = atoi(argv[THR_QNT_POS]);
    for (int i = 0; i < threads_num; ++i) {
        threads.push_back(new eBPF(results, files));
    }

    for (int i = 0; i < threads_num; ++i) {
        threads[i]->start();
    }

    for (int i = 0; i < threads_num; ++i) {
        threads[i]->join();
        delete threads[i];
    }

    results.print();

    return 0;
}
