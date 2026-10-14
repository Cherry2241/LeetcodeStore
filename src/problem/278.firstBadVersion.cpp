#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_278_firstBadVersion {
    class Solution {
    public:
        int bad;
		bool isBadVersion(int version) {
			return version >= bad;
		}
        int firstBadVersion(int n) {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (isBadVersion(mid) == true)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return r;
        }
    };
    bool CheckCase(int n,const int& expected, string& message) {
        Solution solver;
        solver.bad = expected;
        const int actual = solver.firstBadVersion(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(5,4, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("278.firstBadVersion", RunChecks);
}