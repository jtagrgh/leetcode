// https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        auto valid_set = set<int>{};
        auto min_diff = INT_MAX;

        for (auto it = nums.begin(); it != nums.end() - x; it++) {
            valid_set.insert(*it);
            const auto checkit = it + x;
            const auto nearest_element_gt_checkit = valid_set.upper_bound(*checkit);
            if (nearest_element_gt_checkit != valid_set.end()) {
                min_diff = min(min_diff, *nearest_element_gt_checkit - *checkit);
            }
            if (nearest_element_gt_checkit != valid_set.begin()) {
                min_diff = min(min_diff, *checkit - *prev(nearest_element_gt_checkit));
            }
        }

        return min_diff;
    }
};