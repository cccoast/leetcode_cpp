#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
void groupAnagrams();
class Solution {
	unordered_map<string, vector<string>> group;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		for (auto& s : strs) {
			string key = s;
			sort(key.begin(),key.end());
			group[key].push_back(s);
		}
		vector<vector<string>> ret;
		for (auto& temp : group) {
			ret.push_back(std::move(temp.second));
		}
		return ret;
	}
};