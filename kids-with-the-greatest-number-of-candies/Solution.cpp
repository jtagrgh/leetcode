// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for (const auto& c: candies) {
            if (c > max) max = c;
        }

        auto ret = vector<bool>{};
        for (const auto& c: candies) {
            if (c + extraCandies >= max) {
                ret.push_back(true);
            } else {
                ret.push_back(false);
            }
        }

        return ret;
    }
};