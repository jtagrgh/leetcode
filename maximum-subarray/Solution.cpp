// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cmax = nums[0];
        int gmax = nums[0];
        
        for (auto p = nums.begin()+1; p < nums.end(); p++) {
            cmax = max(cmax + *p, *p);
            if (cmax > gmax) gmax = cmax;
        }
        
        return gmax;
    }
};