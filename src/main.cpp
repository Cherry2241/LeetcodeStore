#include <algorithm>
#include <iostream>
#include <string>

#include "ProblemRegistry.h"

namespace {

void PrintAvailableProblems() {
    const std::vector<ProblemEntry>& problems = GetProblems();
    std::cout << "Available problems:" << '\n';
    for (const ProblemEntry& problem : problems) {
        std::cout << "  - " << problem.name << '\n';
    }
}

int RunOneProblem(const ProblemEntry& problem) {
    std::string message;
    const bool passed = problem.verify(message);
    std::cout << "Problem: " << problem.name << '\n';
    std::cout << "Result: " << (passed ? "PASS" : "FAIL") << '\n';

    if (!message.empty()) {
        std::cout << "Detail: " << message << '\n';
    }

    return passed ? 0 : 1;
}

}  // namespace

int main() {
    const std::string problem = "45.jump";

    const ProblemEntry* entry = FindProblemByName(problem);
    
    if (entry == nullptr) {
        std::cerr << "Problem not found: " << problem << '\n';
        PrintAvailableProblems();
        return 1;
    }

    return RunOneProblem(*entry);
}