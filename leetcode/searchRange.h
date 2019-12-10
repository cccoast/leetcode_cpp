#include <vector>
#include <algorithm>
using namespace std;

void searchRange();
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0; 
		int right = nums.size();
		int first = -1, last = -1;
		bool flag = false;
		while (left < right) {
			int mid = floor(left + right) / 2;
			if (nums[mid] > target) {
				right = mid;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				first = mid;
				if (mid > left && nums[mid - 1] == nums[mid]) {
					right = mid;
				}
				else break;
			}
		}
		left = first;
		right = nums.size();
		if(first != -1)
			while (left < right) {
				int mid = floor(left + right) / 2;
				if (nums[mid] > target) {
					right = mid;
				}
				else if (nums[mid] < target) {
					left = mid + 1;
				}
				else {
					last = mid;
					if (mid + 1 < right && nums[mid + 1] == nums[mid])
						left = mid + 1;
					else break;
				}
			}
		return vector<int>{first, last};
	}
};