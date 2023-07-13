#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
void subsetsWithDup();
class Sol {
	vector<vector<int>> v;
	map<int,int> cache;
	vector<int> occur;
	set<string> used;
public:
	Sol() :v{}, occur{}, cache{}
	{
	}

	void dfs(vector<int>& nums, int l, int max_length, vector<int>& subset) {
		if (subset.size() >= max_length) {
			string s;
			for (char c : subset) {
				s.push_back(c);
			}
			if (used.find(s) == used.end()) {
				this->v.push_back(subset);
				used.insert(s);
			}
			return;
		}
		if (l >= nums.size()) return;
		for (int i = l; i < nums.size(); i++) {
			subset.push_back(nums[i]);
			dfs(nums, i + 1, max_length, subset);
			subset.pop_back();
		}
	}

	void findn(vector<int>& nums,int max_length) {
		vector<int> subset;
		for (int i = 0; i < max_length; i++) {
			dfs(nums, i, max_length, subset);
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int value = nums[i];
			auto iter = cache.find(value);
			if (iter == cache.end()) {
				cache.insert(make_pair(value,1));
			}
			else {
				cache[value]++;
			}
			int t = cache[value];
			occur.push_back(t);
		}
		for (int i = 0; i <= nums.size(); i++) {
			findn(nums, i);
		}
		v.push_back(vector<int>());
		return v;
	}
};