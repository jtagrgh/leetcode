// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        bool pmap[1000][1000] = {false};
        int gm = 0;
        int gml;
        
        for (int d = 0; d < s.size(); d++) {
            l = 0;
            r = 0;
            do {
                r = l + d;
                if (s[r] == s[l] && (d <= 1 || pmap[l+1][r-1] == true)) {
                    pmap[l][r] = true;
                    if (d + 1 > gm) {
                        gm = d + 1;
                        gml = l;
                    }
                }
                l++;
            } while (r < s.size() - 1);
        }
        
        return s.substr(gml, gm);
    }
};