#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include"helper/ListNodeHelper.h"
using namespace std;
namespace problem_234_isPalindrome {
    class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            vector<int> l;
            while (head != NULL)
            {
                l.push_back(head->val);
                head = head->next;
            }
            int i, len = l.size();
            for (i = 0;i < len / 2;i++)
            {
                if (l[i] != l[len - i - 1]) return false;
            }
            return true;
        }
    };
    bool CheckCase(ListNode* head, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isPalindrome(head);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(helper::MakeList({1,2,2,1}), true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("234.isPalindrome", RunChecks);
}