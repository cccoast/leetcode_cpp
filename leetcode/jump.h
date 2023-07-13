#pragma once
#include <vector>
#include <iostream>
using namespace std;
void jump();
class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[10000 + 1] = { 0 };
        for (int i = 1; i < 10000 + 1; i++) {
            dp[i] = 9999999;
        }
        for (int i = 0; i < nums.size(); i++ ) {
            for (int j = 1; j <= nums[i]; j++) {
                dp[i + j] = dp[i] + 1 < dp[i + j] ? dp[i] + 1 : dp[i + j];
            }
        }
        return dp[nums.size()-1];
    }
};