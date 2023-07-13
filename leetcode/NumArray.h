#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NumArray {
    int block_size;
    vector<int> block;
    vector<int> _nums;
public:
    NumArray(vector<int>& nums) {
        block_size = pow(nums.size(), 0.5);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if ((i + 1) % block_size == 0) {
                block.emplace_back(sum);
                sum = 0;
            }
            _nums.emplace_back(nums[i]);
        }
        if (nums.size() % block_size != 0) {
            block.emplace_back(sum);
        }
    }

    void update(int index, int val) {
        block[index / block_size] += val - _nums[index];
        _nums[index] = val;
    }

    int sumRange(int left, int right) {
        int left_block = left / block_size;
        int right_block = right / block_size;
        int total = [&]() {
            int sum = 0;
            for (int i = left_block; i < right_block; i++) {
                sum += block[i];
            }
            return sum;
        }();
        int leftv = [&]() {
            int sum = 0;
            for (int i = left_block * block_size; i < left; i++)
                sum += _nums[i];
            return sum;
        }();
        total -= leftv;
        int rightv = [&]() {
            int sum = 0;
            for (int i = right_block * block_size; i <= right; i++)
                sum += _nums[i];
            return sum;
        }();
        total += rightv;
        return total;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */