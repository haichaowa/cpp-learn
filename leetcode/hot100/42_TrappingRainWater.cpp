//
// Created by wanghaichao on 2025/7/30.
//

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> stack;
        for(int i=0; i<n; i++){
            while(!stack.empty() && height[i]>=height[stack.back()]){
                int midh = height[stack.back()];
                stack.pop_back();
                if(!stack.empty()){
                    int left = stack.back();
                    int w = i-left-1;
                    int h = min(height[i], height[left]) - midh;
                    res += w*h;
                }
            }
            stack.emplace_back(i);
        }

        return res;
    }
};