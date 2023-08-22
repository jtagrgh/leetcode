// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq_map;
        for (const auto &i: s) {
            if (freq_map.find(i) == freq_map.end()) {
                freq_map[i] = 1;
            } else {
                freq_map[i]++;
            }
        }
        
        int char_count = 0;
        bool mid_used = false;
        for (const auto &i: freq_map) {
            char_count += 2 * (i.second / 2);
            if (mid_used == false && i.second % 2 == 1) {
                mid_used = true;
                char_count++;
            }
        }
        
        return char_count;
    }
};