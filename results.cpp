#include "results.h"
#include "lock.h"

#define CYCLIC_MESSAGE " FAIL: cycle detected"
#define UNUSED_MESSAGE " FAIL: unused instructions detected"
#define GOOD_MESSAGE " GOOD"

Results::Results() {}

void Results::addResult(const std::string &fileName,
                    bool isCyclic, bool unusedInstr) {
    Lock l(m);
    if (isCyclic) {
        results.push_back(fileName + CYCLIC_MESSAGE);
    } else if (unusedInstr) {
        results.push_back(fileName + UNUSED_MESSAGE);
    } else {
        results.push_back(fileName + GOOD_MESSAGE);
    }
}

void Results::print() {
    results.sort();
    for (auto &result : results) {
        std::cout << result << std::endl;
    }
}

Results::~Results() {}
