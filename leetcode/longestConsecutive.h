#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v(nums.size(),1);
        int max_length = nums.size() > 0 ? 1 : 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                v[i] = v[i - 1] + 1;
                if (v[i] > max_length) {
                    max_length = v[i];
                }
            }
            else if (nums[i] == nums[i - 1]) {
                v[i] = v[i - 1];
            }
        }
        return max_length;
    }
};

void longestConsecutive();
