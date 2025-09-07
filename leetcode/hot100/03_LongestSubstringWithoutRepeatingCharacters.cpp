//
// Created by haichao on 2025-07-31.
//
#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n<=1) return n;
        int res = 1;
        unordered_map<char, int> um;
        int left = 0, right = 0;
        while(right<n){
            um[s[right]]++;
            while(left<right && um[s[right]]>1){
                um[s[left]]--;
                left++;
            }
            if(right-left+1>res){
                res = right - left + 1;
            }
            right++;
        }
        return res;
    }
};

TEST(LengthOfLongestSubstring, Example1) {
    Solution s;
    string input = "abcabcbb";
    auto res = s.lengthOfLongestSubstring(input);
    ASSERT_EQ(res, 3);
}

TEST(LengthOfLongestSubstring, Example2) {
    Solution s;
    string input = "bbbbb";
    auto res = s.lengthOfLongestSubstring(input);
    ASSERT_EQ(res, 1);
}

TEST(LengthOfLongestSubstring, Example3) {
    Solution s;
    string input = "pwwkew";
    auto res = s.lengthOfLongestSubstring(input);
    ASSERT_EQ(res, 3);
}
