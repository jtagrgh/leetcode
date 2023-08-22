// https://leetcode.com/problems/max-pair-sum-in-an-array

class Solution {
public:
    int maxSum(vector<int>& nums) {
        auto buckets = vector<priority_queue<int>>(10);
        for (const auto& n: nums) {
            int num = n;
            int max = 0;
            while (num > 0) {
                if (num % 10 > max) max = num % 10;
                num /= 10;
            }
            buckets[max].push(n);
        }
        int max = -1;
        for (auto& b: buckets) {
            if (b.size() < 2) continue;
            int local_max = b.top();
            b.pop();
            local_max += b.top();
            max = std::max(local_max, max);
        }
        return max;
    }
};