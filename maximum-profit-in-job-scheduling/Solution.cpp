// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        vector<int> memo(50000);

        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        memo[jobs.size()-1] = jobs[jobs.size()-1][2];

        for (int i_0 = jobs.size()-2; i_0 >= 0; i_0--) {
            auto i_1 = distance(jobs.begin(), 
                lower_bound(jobs.begin(), jobs.end(), jobs[i_0][1],
                [](const auto &a, const auto& b) {
                    return a[0] < b;
                }
            ) );
            memo[i_0] = max(
                jobs[i_0][2] + ( i_1 >= jobs.size() ? 0 : memo[i_1] ),
                (i_0 + 1) >= jobs.size() ? 0 : memo[i_0 + 1]
            );
        }

        return memo[0];
    }
};