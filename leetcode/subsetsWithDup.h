#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
void subsetsWithDup();
class Solution {
	vector<vector<int>> v;
	map<int,int> cache;
	vector<int> occur;
public:
	Solution() :v(0),occur(0) {};
	void dfs(vector<int>& nums, int l, int max_length, vector<int>& subset) {
		if (subset.size() >= max_length) {
			this->v.push_back(subset);
			return;
		}
		if (l >= max_length) return;
		for (int i = l; i < max_length; i++) {
			if (subset.size() + 1 >= occur[i]) {
				subset.push_back(nums[i]);
				dfs(nums, i + 1, max_length, subset);
				subset.pop_back();
			}
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
				cache[value] = 1;
			}
			else {
				cache[value]++;
			}
			int t = cache[value];
			occur.push_back(t);
		}
		for (int i = 0; i < nums.size(); i++) {
			findn(nums, i);
		}
		return v;
	}
};