# 生成测试用例

```text
    参考下面例子：
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    
    TEST(longestConsecutive, Example1){
        Solution s;
        vector<int> nums{100,4,200,1,3,2};
        auto res = s.longestConsecutive(nums);
        ASSERT_EQ(res, 4);
    }
    
    给我函数 ContainerWithMostWater 对应的测试用例1
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```
