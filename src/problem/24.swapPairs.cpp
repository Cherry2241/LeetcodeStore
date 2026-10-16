#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/ListNodeHelper.h"
using namespace std;
namespace problem_24_swapPairs {
    class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return head;
            ListNode* newHead = head->next;
            head->next = swapPairs(head->next->next);
            newHead->next = head;
            return newHead;
        }
    };
    bool CheckCase(ListNode* head, const ListNode* expected, string& message) {
        Solution solver;
        const ListNode* actual = solver.swapPairs(head);

        if (helper::IsSameList(actual,expected)) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(helper::MakeList({1,2,3,4}), helper::MakeList({2,1,4,3}), message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("24.swapPairs", RunChecks);
}