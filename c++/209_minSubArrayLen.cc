#include <climits>
#include <cstdint>
#include<vector>

class Solution{
    public:
    int minSubArrayLen(std::vector<int>& nums, int val){
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for (int j = 0; j<nums.size(); j++){
            sum += nums[j];

            while(sum > val){
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                 sum -= nums[i++];
            }

        }
        return result == INT_MAX ? 0 : result;
    }
};