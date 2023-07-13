#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct three {
    int value;
    int index;
    int power;
};
bool cmp(const three& a, const three& b) { return a.value < b.value; }
class Solution {    
    int length;
    vector<three> xheap;
public:
    inline void add_heap(int index, int pow, vector<int>& primes) {
        if (index < length) {
            xheap.push_back(three{ int(std::pow(primes[index + 1], pow)),index+1,pow });
            push_heap(xheap.begin(), xheap.end(), cmp);
            sort_heap(xheap.begin(), xheap.end(), cmp);
        }
        xheap.emplace_back(three{ int(std::pow(primes[index], pow + 1)),index,pow + 1});
        push_heap(xheap.begin(), xheap.end(), cmp);
        sort_heap(xheap.begin(), xheap.end(), cmp);
   
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        xheap.clear();
        length = primes.size();
        int index = 0, pow = 1, count = n - 1;
        int desired_value = primes[index];
        add_heap(index, pow,primes);
        while (count > 0) {
            count--;
            pop_heap(xheap.begin(), xheap.end(), cmp);
            three least = xheap.back();
            xheap.pop_back();
            add_heap(least.index, least.power, primes);
            desired_value = least.value;
        }
        return desired_value;
    }
};


