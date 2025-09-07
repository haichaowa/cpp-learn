//
// Created by haichao on 2025-09-07.
//
#include "common.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==0 && k==0) return {};

        deque<int> dq;
        vector<int> res(nums.size()-k+1);

        for(int i=1-k, j=0; j<nums.size(); i++, j++){
            if(i>0 && nums[i-1] == dq.front()){
                dq.pop_front();
            }

            while(!dq.empty() && nums[j] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            if(i>= 0){
                res[i] = dq.front();
            }
        }

        return res;
    }
};

TEST(maxSlidingWindow, Example1) {
    Solution sol;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> res = sol.maxSlidingWindow(nums, 3);

    vector<int> expected{3,3,5,5,6,7};
    ASSERT_EQ(res, expected);
}
