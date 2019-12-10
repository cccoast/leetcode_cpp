
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

void permuteUnique();
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> v;
		sort(nums.begin(), nums.end());
		do {
			vector<int> curp;
			copy(nums.begin(), nums.end(), back_inserter(curp));
			v.push_back(curp);
		} while (next_permutation(nums.begin(), nums.end()));
		return v;
	}
};