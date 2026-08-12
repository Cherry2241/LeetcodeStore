#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"

using namespace std;

namespace problem_49_groupanagrams {

	class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			int len = strs.size(), i, j;
			string s;
			vector<vector<string>> ans;
			map<string, vector<string>> hashMap;
			for (i = 0;i < len;i++)
			{
				s = strs[i];
				sort(s.begin(), s.end());
				auto it = hashMap.find(s);
				if (it != hashMap.end())
				{
					it->second.push_back(strs[i]);
				}
				else
				{
					hashMap.emplace(s, vector{ strs[i] });
				}
			}
			for (auto& p : hashMap)
			{
				ans.push_back(p.second);
			}
			return ans;
		}
	};


	bool CheckCase(vector<string> strsInput, const vector<vector<string>>& expected, string& message) {
		Solution solver;
		const std::vector<vector<string>> actual = solver.groupAnagrams(strsInput);

		if (actual == expected) {
			return true;
		}

		message = "CheckCase failed";
		return false;
	}

	bool RunChecks(std::string& message) {
		if (!CheckCase(vector<string>{"eat", "tea", "tan", "ate", "nat", "bat"}, vector<vector<string>>{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}, message)) {
			return false;
		}

		message = "1 cases passed";
		return true;
	}

	ProblemRegistrar registrar("49.Group Anagrams", RunChecks);

}