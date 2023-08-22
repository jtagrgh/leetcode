// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, l_sum = 0;
        vector<int>::const_iterator i, nums_end = nums.end();
        
        for (const auto &i: nums) {
            total += i;
        }
        int ind = 0;
        for (const auto &i: nums) {
            if (l_sum == (total - l_sum - i)) {return ind;}
            else {l_sum += i; ind++;}
        }
        
        return -1;
    }
};