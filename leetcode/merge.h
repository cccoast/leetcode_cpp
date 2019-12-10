#ifndef __MERGE_H__
#define __MERGE_H__
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void merge();
class Solution {
public: 
	static bool merge_cmp(vector<int>&a, vector<int>&b) {
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		std::sort(intervals.begin(), intervals.end(), Solution::merge_cmp);
		for (auto& interval : intervals) {
			int left = interval[0], right = interval[1];
			bool merged = false;
			for (auto& v : result) {
				if (v[1] >= left) {
					v[1] = right > v[1] ? right : v[1];
					merged = true;
					break;
				}
			}
			if (!merged) {
				result.push_back(interval);
			}
		}
		return result;
	}
};
#endif