// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) return 1;
        unordered_map<char, int> pos_map;
        int gm = 0, cm = 0;
        // [l, r), indexes
        int l = 0, r = 1;
        pos_map[s[l]] = l;
        
        while (r < s.size()) {
            char rchar = s[r];
            if (pos_map.find(rchar) == pos_map.end()) {
                pos_map[rchar] = r;
            } else {
                if (pos_map[rchar] != r) {
                    if (l < pos_map[rchar] + 1)
                        l = pos_map[rchar] + 1;
                    pos_map[rchar] = r;
                }
            }
            r++;
            cm = (r - l);
            gm = max(cm, gm);
        }
        
        return gm;
    }
};