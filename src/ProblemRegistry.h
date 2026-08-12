#pragma once

#include <string>
#include <vector>

using VerifyFunction = bool(*)(std::string& message);

struct ProblemEntry {
    std::string name;
    VerifyFunction verify;
};

void RegisterProblem(const char* name, VerifyFunction verify);
const std::vector<ProblemEntry>& GetProblems();
const ProblemEntry* FindProblemByName(const std::string& name);

class ProblemRegistrar {
public:
    ProblemRegistrar(const char* name, VerifyFunction verify);
};
