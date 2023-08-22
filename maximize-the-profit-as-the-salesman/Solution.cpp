// https://leetcode.com/problems/maximize-the-profit-as-the-salesman

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        unordered_map<int,int> memo;
        memo[offers.size()-1] = offers.back()[2];
        for (int i0 = offers.size()-2; i0 >= 0; i0--) {
            int i1 = std::distance(
                offers.begin(),
                upper_bound( offers.begin(), offers.end(), offers[i0][1],
                    [](const int& a, const auto& b) { 
                       return a < b[0];
                    }
                )
            );
            memo[i0] = max(
                offers[i0][2] + (i1 >= offers.size() ? 0 : memo[i1]),
                (i0 + 1) >= offers.size() ? 0 : memo[i0 + 1]
            );
        }

        return memo[0];
    }
};