// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        string::const_iterator s_itr = s.begin();
        if (s.size() == 0) return true;
        
        for (const auto &c: t) {
            if (c == *s_itr) s_itr++;
            if (s_itr == s.end()) return true;
        }
        
        return false;
    }
};