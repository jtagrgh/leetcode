// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() == 1) return 1;
        int l = 0, r = 1;
        int gm = 0;
        unordered_map<char, int> freq;
        freq[s[0]] = 1;
        
        while (r < s.size()) {
            if (freq.find(s[r]) == freq.end()) {
                while (freq.size() > 1) {
                    freq[s[l]]--;
                    if (freq[s[l]] == 0) freq.erase(s[l]);
                    l++;
                }
                freq[s[r]] = 1;
            } else {
                freq[s[r]]++;
            }
            r++;
            gm = max(gm, r-l);
        }
        
        return gm;
    }
};