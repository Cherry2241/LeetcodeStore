#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_303_NumArray {
    class NumArray {
    public:
        vector<int> sum;
        NumArray(vector<int>& nums) {
            int i, len = nums.size();
            sum.resize(len + 1);
            for (i = 0;i < len;i++)
            {
                sum[i + 1] = sum[i] + nums[i];
            }
        }

        int sumRange(int left, int right) {
            return sum[right + 1] - sum[left];
        }
    };
}
