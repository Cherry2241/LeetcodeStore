#include <initializer_list>
#include <vector>

#include "helper/ListNode.h"
#include "helper/ListNodeHelper.h"
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"

namespace problem_2_addtwonumbers {

class Solution {
public:
    ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};

bool CheckCase(std::initializer_list<int> left,
               std::initializer_list<int> right,
               const std::vector<int>& expected,
               const char* caseName,
               std::string& message) {
    Solution solver;
    ListNode* l1 = helper::MakeList(left);
    ListNode* l2 = helper::MakeList(right);
    ListNode* result = solver.addTwoNumbers(l1, l2);
    const std::vector<int> actual = helper::ToVector(result);

    helper::FreeList(l1);
    helper::FreeList(l2);
    helper::FreeList(result);

    return helper::VerifyVectorEqual(caseName, expected, actual, message);
}

bool RunChecks(std::string& message) {
    if (!CheckCase({2, 4, 3}, {5, 6, 4}, {7, 0, 8}, "normal case", message)) {
        return false;
    }

    if (!CheckCase({0}, {0}, {0}, "zero case", message)) {
        return false;
    }

    if (!CheckCase({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1},
                   "carry chain", message)) {
        return false;
    }

    message = "3 cases passed";
    return true;
}

ProblemRegistrar registrar("2. AddTwoNumbers", RunChecks);

}  // namespace problem_2_addtwonumbers
