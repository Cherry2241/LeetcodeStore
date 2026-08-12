#include "ProblemRegistry.h"

#include <algorithm>
#include <cctype>

namespace {

std::vector<ProblemEntry>& MutableProblems() {
    static std::vector<ProblemEntry> problems;
    return problems;
}

std::string NormalizeProblemKey(const std::string& input) {
    std::string normalized;
    normalized.reserve(input.size());
    for (char ch : input) {
        if (!std::isspace(static_cast<unsigned char>(ch))) {
            normalized.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
        }
    }
    return normalized;
}

}  // namespace

void RegisterProblem(const char* name, VerifyFunction verify) {
    if (name == nullptr || verify == nullptr) {
        return;
    }

    std::vector<ProblemEntry>& problems = MutableProblems();
    const std::string key = NormalizeProblemKey(name);
    auto it = std::find_if(problems.begin(), problems.end(), [&](const ProblemEntry& entry) {
        return NormalizeProblemKey(entry.name) == key;
    });

    if (it == problems.end()) {
        problems.push_back({name, verify});
    }
}

const std::vector<ProblemEntry>& GetProblems() {
    return MutableProblems();
}

const ProblemEntry* FindProblemByName(const std::string& name) {
    const std::vector<ProblemEntry>& problems = GetProblems();
    const std::string key = NormalizeProblemKey(name);
    auto it = std::find_if(problems.begin(), problems.end(), [&](const ProblemEntry& entry) {
        return NormalizeProblemKey(entry.name) == key;
    });

    if (it == problems.end()) {
        return nullptr;
    }

    return &(*it);
}

ProblemRegistrar::ProblemRegistrar(const char* name, VerifyFunction verify) {
    RegisterProblem(name, verify);
}
