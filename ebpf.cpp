#include "ebpf.h"

eBPF::eBPF(const char *filesNames[], Results &results, Files &files) :
        filesNames(filesNames), results(results), files(files) {}


void eBPF::run() {
    FileParser fileParser(filesNames, files);
    std::string buffer;
    while (fileParser.areFilesToProcces()) {
        Digraph graph;
        std::map<std::string, std::vector<std::string>> instructions;
        fileParser.getInstructions(buffer, instructions);
        std::cout << fileParser.proccessedFile() << std::endl;
        for (auto instr : instructions) {
            for (auto &line : instr.second) {
                graph.addEdge(instr.first, line);
                std::cout << instr.first << "->" << line << std::endl;
           }
        }
        results.addResult(fileParser.proccessedFile(),
                        graph.isCyclic(), !graph.isAConnectedGraph());
    }
}

eBPF::~eBPF() {
}
