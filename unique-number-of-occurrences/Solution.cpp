// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> key_map;
        for (const auto& i: arr) {
            if (key_map.find(i) != key_map.end()) {
                key_map.at(i)++;
            } else {
                key_map.insert({i, 0});
            }
        }

        unordered_set<int> freqs;
        for (const auto& p : key_map) {
            const auto& f = p.second;
            if (freqs.find(f) != freqs.end()) {
                return false;
            } else {
                freqs.insert(f);
            }
        }

        return true;
    }
};