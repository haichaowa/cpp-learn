//
// Created by haichao on 2025-07-26.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <gtest/gtest.h>
#include <fmt/ranges.h>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            auto it = um.find(target-nums[i]);
            if(it != um.end()){
                return {um[target-nums[i]], i};
            }
            um[nums[i]] = i;
        }

        return {};
    }
};

TEST(TwoSumTest, Example1) {
    Solution s;
    std::vector<int> nums{2,7,11,15};
    std::vector<int> expected{0, 1};
    auto res = s.twoSum(nums, 9);
    ASSERT_EQ(res, expected);
}