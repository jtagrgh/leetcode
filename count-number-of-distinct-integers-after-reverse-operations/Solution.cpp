// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        list<int> rev;
        for (const auto &i: nums) {
            string num = to_string(i);
            reverse(num.begin(), num.end());
            int rev_num = stoi(num);
            rev.push_back(rev_num);
        }
        
        unordered_set<int> outmap;
        for (auto &i: nums) {
            outmap.insert(i);
        }
        for (auto &i: rev) {
            outmap.insert(i);
        }
        
        return outmap.size();
    }
};