#include <set>
#include <string>
#include <iostream>
using namespace std;
void numDecodings();
class Solution {
public:
	int dfs(string& s, int start) {
		if (start >= s.length()) return 1;
		if ((s[start] - '1' + 1) == 0) return 0;
		int num;
		int count = 0;
		if (start + 1 < s.length()) {
			num = (s[start] - '1' + 1) * 10 + ( s[start + 1] - '1' + 1);
			if(num <= 26 && num > 0)
				count += dfs(s, start + 2);
		}
		count += dfs(s, start + 1);
		return count;
	}
	int numDecodings(string s) {
		return dfs(s, 0);
	}
};