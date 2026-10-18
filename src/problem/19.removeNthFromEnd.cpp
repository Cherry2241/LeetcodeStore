#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/ListNodeHelper.h"
using namespace std;
namespace problem_19_removeNthFromEnd {
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* p1 = head, * p2 = head;
            int i;
            for (i = 1;i <= n;i++) p2 = p2->next;
            if (p2 == NULL)
            {
                return head->next;
            }
            while (p2->next != NULL)
            {
                p2 = p2->next;
                p1 = p1->next;
            }
            p1->next = p1->next->next;
            return head;
        }
    };
    bool CheckCase(ListNode* head,int n, const ListNode* expected, string& message) {
        Solution solver;
        const ListNode* actual = solver.removeNthFromEnd(head,n);

        if (helper::IsSameList(actual, expected)) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(helper::MakeList({ 1,2,3,4 ,5}),2, helper::MakeList({ 1,2,3,5 }), message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("19.removeNthFromEnd", RunChecks);
}