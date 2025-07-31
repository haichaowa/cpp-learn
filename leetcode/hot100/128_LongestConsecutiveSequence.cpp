//
// Created by wanghaichao on 2025/7/27.
//
#include <vector>
#include <unordered_set>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
//        for(const int &num : nums){
//            s.insert(num);
//        }

        int res = 0;
//      for(const int &num : nums){
        for(const int &num : s){
                if(!s.count(num-1)){
                    int cur = num;
                    int tl = 1;
                    while(s.count(cur+1)){
                        tl++;
                        cur++;
                    }

                    // if(tl > res){
                    //     res = tl;
                    // }
                    res = max(res, tl);
                }
        }
        return res;
    }
};

/*
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */
TEST(longestConsecutive, Example1){
    Solution s;
    vector<int> nums{100,4,200,1,3,2};

    auto res = s.longestConsecutive(nums);
    ASSERT_EQ(res, 4);
}