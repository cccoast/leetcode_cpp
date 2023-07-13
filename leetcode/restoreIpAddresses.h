#pragma once
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

using namespace std;

void restoreIpAddresses();

class Solution {
public:
	vector<string> restoreIpAddresses(std::string s) {
		int len = s.length();
		int i, j, k;
		vector<tuple<int, int, int>> valid;

		auto check_unit = [&s](int left, int right) {
			if (s[left] == '0' && left + 1 == right) return true;
			else if (s[left] == '0' && left + 1 < right)  return false;
			else {
				int ip = stoi(s.substr(left, right - left));
				return ip >= 0 && ip <= 255;
			}
		};

		auto check_all = [len, &check_unit](int i, int j, int k) {
			if (check_unit(0, i) && check_unit(i, j) && check_unit(j, k) && check_unit(k, len)) {
				return true;
			}
			else {
				return false;
			}
		};

		for (i = 1; i <= 3; i++) {
			for (j = i + 1; j <= i + 3; j++) {
				for (k = j + 1; k <= j + 3 && k < len; k++) {
					if (k + 3 >= len && check_all(i, j, k)) {
						valid.push_back({ i,j, k });
					}
				}
			}
		}

		vector<string> result;
		for (auto t : valid) {
			string tmp = s.substr(0, std::get<0>(t)) + '.' + s.substr(std::get<0>(t), std::get<1>(t) - std::get<0>(t))
				+ '.' + s.substr(std::get<1>(t), std::get<2>(t) - std::get<1>(t)) + '.' + s.substr(std::get<2>(t), len - std::get<2>(t));
			result.push_back(tmp);
		}

		return result;
	}
};