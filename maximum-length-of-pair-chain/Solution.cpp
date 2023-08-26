// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
            [](const auto& a, const auto& b){ return a[1] < b[1]; } );

        int l = 1;
        int k = 0;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > pairs[k][1]) {
                l++;
                k = i;
            }
        }

        return l;
    }
};