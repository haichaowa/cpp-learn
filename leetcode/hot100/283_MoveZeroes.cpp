//
// Created by wanghaichao on 2025/7/27.
//

#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n){
            if(nums[right]){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

TEST(moveZeroes, Example1) {
    Solution s;
    vector<int> nums{0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    vector<int> expected{1, 3, 12, 0, 0};
    ASSERT_EQ(nums, expected);
}