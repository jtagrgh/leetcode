// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int cmax = prices[1] - prices[0];
        int gmax = cmax > 0 ? cmax : 0;
        
        for (auto p = prices.begin()+1; p < prices.end()-1; p++) {
            cmax = max(cmax + (*(p+1) - *p), (*(p+1) - *p));
            if (cmax > gmax) gmax = cmax;
        }
        
        return gmax;
    }
};