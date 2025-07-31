//
// Created by wanghaichao on 2025/7/27.
//
#include <vector>
#include <unordered_set>
#include <string>
#include <gtest/gtest.h>
#include "math.h"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r){
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if(height[l] <= height[r]){
                ++l;
            }else{
                --r;
            }
        }
        return ans;

    }
};

TEST(ContainerWithMostWater, Example1) {
    Solution s;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    auto res = s.maxArea(height);
    ASSERT_EQ(res, 49);
}