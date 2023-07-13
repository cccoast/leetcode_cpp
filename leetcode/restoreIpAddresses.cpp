#include "restoreIpAddresses.h"

void restoreIpAddresses() {
	auto s = "25525511135";
	auto sol = Solution();
	auto result = sol.restoreIpAddresses(s);
	for (auto i : result) {
		cout << i << ' ';
	}
	cout << endl;
}