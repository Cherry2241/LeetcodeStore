#include <string>
#include<unordered_set>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/ListNodeHelper.h"
using namespace std;
namespace problem_142_detectCycle {
    class Solution {
    public:
        ListNode* detectCycle(ListNode* head) {
            unordered_set<ListNode*> s;
            while (head != NULL)
            {
                if (s.count(head))
                {
                    return head;
                }
                s.insert(head);
                head = head->next;
            }
            return NULL;
        }
    };
}