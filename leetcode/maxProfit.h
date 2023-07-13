#define __MAX_PROFIT_H__
#include <vector>
#include <iostream>
using namespace std;
namespace np_max_profit {
    class Solution {
    private:
        int cache[5001];
        int _size;
    public:
        Solution() {
            memset(cache, -1, sizeof(int) * 5001);
        }

        int dfs(vector<int>& prices, int left) {
            if (left >= _size) return 0;
            else if (left + 1 == _size) return 0;
            else if (cache[left] >= 0) return cache[left];
            else {
                int max_profit = -1;
                for (int i = left + 1; i < _size; i++) {                    
                    if (dfs(prices, i) > max_profit)
                        max_profit = dfs(prices, i);
                    if ((prices[i] - prices[left]) + dfs(prices, i + 2) > max_profit)
                        max_profit = (prices[i] - prices[left]) + dfs(prices, i + 2);
                }
                cache[left] = max_profit >= 0 ? max_profit : 0;
                return cache[left];
            }
        }

        int maxProfit(vector<int>& prices) {
            _size = prices.size();
            return dfs(prices, 0);
        }
    };
}