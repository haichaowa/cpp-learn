//
// Created by wanghaichao on 2025/7/27.
//
#include <array>
#include <unordered_map>
#include <iostream>
#include <gtest/gtest.h>
#include <fmt/ranges.h>
#include <functional>
#include <numeric>
#include <random>
#include <string>

class Solution{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        auto arrayHash = [fn = std::hash<int>{}](const std::array<int, 26> &counts)->size_t{
            return std::accumulate(counts.begin(), counts.end(), 0, [&](int acc, int num){
                return (acc<<1) ^ fn(num);
            });
        };
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, decltype(arrayHash)> um(0, arrayHash);
        for(std::string &s: strs){
            // array<int, 26> counter;
            std::array<int, 26> counter{};

            // for(int i=0; i<s.length(); i++){
            //     counter[s[i]-'a']++;
            // }
            for(char c: s){
                counter[c -'a']++;
            }

            um[counter].emplace_back(s);
        }

        for(auto it = um.begin(); it != um.end(); it++){
            res.emplace_back(it->second);
        }

        return res;
    }
};

TEST(GroupAnagramsTest, ArrayInit) {
    std::array<int, 26> counter1;
    std::array<int, 26> counter2{};

    fmt::print("counter1: {}\n", counter1);
    fmt::print("counter2: {}\n", counter2);
}

TEST(GroupAnagramsTest, ArrayHash){
    auto arrayHash = [fn = std::hash<int>{}](const std::array<int, 26> & arr) -> size_t{
        return std::accumulate(arr.begin(), arr.end(), 0, [&](int acc, int num){
           return (acc<<1) ^ fn(num);
        });
    };
    std::array<int, 26> counter{};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int& num : counter) {
        num = dis(gen);
    }

    size_t h = arrayHash(counter);
    std::cout << "hash value: " << h << std::endl;
}

TEST(GroupAnagramsTest, Example1){
    Solution s;
    std::vector<std::string> input{"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> expected{
            {"bat"},
            {"nat","tan"},
            {"ate","eat","tea"}
    };
    std::vector<std::vector<std::string>> res = s.groupAnagrams(input);
    ASSERT_EQ(res, expected);
}