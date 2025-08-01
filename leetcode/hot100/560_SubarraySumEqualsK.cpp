//
// Created by haichao on 2025-08-01.
//

#include "common.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0] = 1;
        int presum = 0;
        int res = 0;
        for(int i=0; i < nums.size(); i++){
            presum += nums[i];
            if(um.find(presum - k) != um.end()){
                res += um[presum-k];
            }
            um[presum]++;
        }

        return res;
    }
};

TEST(SubarraySum, Example1) {
    Solution sol;
    vector<int> input{1, 1, 1};
    int res = sol.subarraySum(input, 2);
    ASSERT_EQ(res, 2);
}