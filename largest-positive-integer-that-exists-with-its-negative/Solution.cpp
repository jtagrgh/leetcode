// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max = 0;
        for (auto i = nums.begin(); i != nums.end(); i++) {
            for (auto j = nums.begin(); j != nums.end(); j++) {
                if (i != j && *i == -*j) {
                    if (*i > max) max = *i;
                    if (*j > max) max = *j;
                }
            }
        }
        if (max == 0) max = -1;
        return max;
    }
};