#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_125_isPalindrome {
    class Solution {
    public:
        bool isPalindrome(string s) {
            int len = s.size(), left = 0, right = len - 1;
            while(left<right)
            {
                while (left < right && !isalnum(s[left])) left++;
				while (left < right && !isalnum(s[right])) right--;
                if (tolower(s[left]) != tolower(s[right])) return false;
                left++;
                right--;
            }    
            return true;
        }
    };
    bool CheckCase(string s, const bool& expected, string& message) {
        Solution solver;
        const  bool actual = solver.isPalindrome(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("A man, a plan, a canal: Panama", true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("125.isPalindrome", RunChecks);
}