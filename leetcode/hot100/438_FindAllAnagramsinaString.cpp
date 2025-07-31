//
// Created by haichao on 2025-07-31.
//
#include"common.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int, 26> cnts{};
        array<int, 26> cntp{};

        int lp = p.length();
        for(char c: p){
            cntp[c-'a']++;
        }

        vector<int> res;
        for(int i=0; i<s.length(); i++){
            cnts[s[i]-'a']++;
            int j = i - lp + 1;
            if(j<0) continue;

            if(cnts==cntp){
                res.emplace_back(j);
            }

            cnts[s[j]-'a']--;
        }

        return res;
    }
};


TEST(FindAnagrams, Example1) {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> res = sol.findAnagrams(s, p);
    vector<int> expected{0, 6};
    ASSERT_EQ(res, expected);
}