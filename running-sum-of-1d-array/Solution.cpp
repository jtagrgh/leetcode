// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSums;
        int runningSum = 0;
        for (int i: nums) {
            runningSum += i;
            runningSums.push_back(runningSum);
        }
        return runningSums;
    }
};