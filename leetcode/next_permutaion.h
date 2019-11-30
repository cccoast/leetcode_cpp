#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
	 multiset<int> candidate;
	 bool fill_after;
public:
	void nextPermutation(vector<int>& nums) {
		for (int i = nums.size()-1; i >= 0; i--) {
			this->candidate.insert(nums[i]);
			fill_after = false;
			auto pos = candidate.begin();
			for (; pos != candidate.end();pos++) {
				if (*pos > nums[i]) {
					nums[i] = *pos;
					fill_after = true;
					break;
				}
			}
			if (fill_after) {
				this->candidate.erase(pos);
				for (auto v: this->candidate) {
					nums[++i] = v;
				}
				return;
			}
		}
		sort(nums.begin(),nums.end());
	}
};