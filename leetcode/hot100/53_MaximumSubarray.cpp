//
// Created by wanghaichao on 2025/10/2.
//
#include "common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>  prefix_sum(n+1);
        int min_value = 0;
        int res = nums[0];
        for(int i=1; i<=n; i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
            if(prefix_sum[i] - min_value > res){
                res = prefix_sum[i] - min_value;
            }
            if (prefix_sum[i]<min_value){
                min_value = prefix_sum[i];
            }
        }
        return res;
    }
};

TEST(maxSubArray, Example1) {
    Solution sol;
    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    int res = sol.maxSubArray(input);
    ASSERT_EQ(res, 6);
}