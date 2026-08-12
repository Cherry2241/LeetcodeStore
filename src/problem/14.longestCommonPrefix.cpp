#include <vector>
#include <string>
#include <algorithm>

namespace problem_14_longestCommonPrefix {
    class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            int len = strs.size(), i, j, min_len = 1000;
            std::string s = "";
            for (i = 0;i < len;i++)
            {
                min_len = std::min(min_len, (int)strs[i].size());
            }
            for (i = 0;i < min_len;i++)
            {
                char c = strs[0][i];
                bool f = true;
                for (j = 1;j < len;j++)
                {
                    if (strs[j][i] != c)
                    {
                        f = false;
                        break;
                    }
                }
                if (!f) break;
                s = s + c;
            }
            return s;
        }
    };
}