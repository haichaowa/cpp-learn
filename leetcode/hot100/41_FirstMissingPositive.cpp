//
// Created by wanghaichao on 2025/10/4.
//
#include "common.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool has_one = false;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                has_one = true;
            }else if(nums[i] <= 0){
                nums[i] = 1;
            }
        }
        if(!has_one) return 1;

        for(int i = 0; i < n; i++){
            int v = abs(nums[i]);
            if(v <= n){
                nums[v-1] = -abs(nums[v-1]);
            }
        }

        for(int i=1; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};

TEST(firstMissingPositive, Example1) {
    Solution sol;
    vector<int> input{3, 4, -1, 1};
    int res = sol.firstMissingPositive(input);
    ASSERT_EQ(res, 3);
}