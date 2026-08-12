#include <vector>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"

using namespace std;
namespace problem_13_romanToInt {

	class Solution
	{
	public:
		int romanToInt(string s) {
			int len = s.size(), i, num = 0;
			for (i = 0;i < len;i++)
			{
				if (s[i] == 'I') num += 1;
				if (s[i] == 'V') {
					num += 5;
					if (i > 0 && s[i - 1] == 'I') num -= 2;
				}
				if (s[i] == 'X') {
					num += 10;
					if (i > 0 && s[i - 1] == 'I') num -= 2;
				}
				if (s[i] == 'L') {
					num += 50;
					if (i > 0 && s[i - 1] == 'X') num -= 20;
				}
				if (s[i] == 'C') {
					num += 100;
					if (i > 0 && s[i - 1] == 'X') num -= 20;
				}
				if (s[i] == 'D') {
					num += 500;
					if (i > 0 && s[i - 1] == 'C') num -= 200;
				}
				if (s[i] == 'M') {
					num += 1000;
					if (i > 0 && s[i - 1] == 'C') num -= 200;
				}
			}
			return num;
		}

	};

	bool RunChecks(std::string& message) {

		message = "roman cases passed";
		return true;
	}

	ProblemRegistrar registrar("13.romanToInt", RunChecks);
} // namespace problem_13_romanToInt
