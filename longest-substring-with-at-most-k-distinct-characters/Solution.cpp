// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        if (s.size() == 1) return 1;
        int l = 0, r = 1;
        int gm = 0;
        unordered_map<char, int> freq;
        freq[s[0]] = 1;
        
        while (r < s.size()) {
            if (freq.find(s[r]) == freq.end()) {
                while (freq.size() > k-1) {
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