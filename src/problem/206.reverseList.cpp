#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_206_reverseList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* pos1 = nullptr, * pos2 = head;
            while (pos2 != nullptr)
            {
                ListNode* next = pos2->next;
                pos2->next = pos1;
                pos1 = pos2;
                pos2 = next;

            }
            return pos1;
        }
    };
}