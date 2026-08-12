#include <unordered_map>
#include <vector>

#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"

namespace problem_1_twosum {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> indexByValue;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int complement = target - nums[i];
            auto it = indexByValue.find(complement);
            if (it != indexByValue.end()) {
                return {it->second, i};
            }
            indexByValue[nums[i]] = i;
        }

        return {};
    }
};

bool CheckCase(const std::vector<int>& numsInput,
               int target,
               const std::vector<int>& expected,
               const char* caseName,
               std::string& message) {
    Solution solver;
    std::vector<int> nums = numsInput;
    const std::vector<int> actual = solver.twoSum(nums, target);

    return helper::VerifyVectorEqual(caseName, expected, actual, message);
}

bool RunChecks(std::string& message) {
    if (!CheckCase({2, 7, 11, 15}, 9, {0, 1}, "normal case", message)) {
        return false;
    }

    if (!CheckCase({3, 3}, 6, {0, 1}, "duplicate values", message)) {
        return false;
    }

    if (!CheckCase({-3, 4, 3, 90}, 0, {0, 2}, "negative values", message)) {
        return false;
    }

    if (!CheckCase({1, 2, 3}, 100, {}, "no solution", message)) {
        return false;
    }

    message = "4 cases passed";
    return true;
}

ProblemRegistrar registrar("1. TwoSum", RunChecks);

}  // namespace problem_1_twosum
