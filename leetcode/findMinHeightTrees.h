#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_map<long long, int> dp;
    int global_least_height;
public:

    int dfs(int father, int cur_edge) {
        if (father != -1) {
            if (dp.find(father * 100000 + cur_edge) != dp.end()) {
                return dp[father * 100000 + cur_edge];
            }
        }
        int least_height = 0;
        auto& v = graph[cur_edge];
        if (v.size() > 0) {
            for (auto next_edge : v) {
                if (next_edge != father) {                    
                    int tmp = dfs(cur_edge, next_edge);
                    least_height = least_height > tmp ? least_height : tmp;
                }
            }
        }
        if (father >= 0)
            dp[father * 100000 + cur_edge] = least_height + 1;
        return least_height + 1;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return vector<int>{0};
        if (n == 2) return vector<int>{0, 1};
        global_least_height = 99999999;
        for (auto& v : edges) {
            if (graph.find(v[0]) == graph.end()) {
                graph[v[0]] = vector<int>();
            }
            if (graph.find(v[1]) == graph.end()) {
                graph[v[1]] = vector<int>();
            }
            graph[v[0]].emplace_back(v[1]);
            graph[v[1]].emplace_back(v[0]);
        }

        for (auto&& [i, j] : graph) {
            if (j.size() == 1) {
                dp[i * 100000 + j[0]] = 1;
            }
        }

        vector<int> nodes;
        int least_height = 999999999;
        for (auto&& [key, value] : graph) {
            int tmp;
            if (value.size() == 1) {
                continue;
            }
            else {
                tmp = dfs(-1, key);
            }
            if (tmp == least_height) {
                nodes.emplace_back(key);
            }
            else if (tmp < least_height) {
                least_height = tmp;
                nodes.clear();
                nodes.push_back(key);
            }
        }
        return nodes;
    }
};