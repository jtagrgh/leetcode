// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) {
            return false;
        }
        for (int w = 1; w <= s.size()/2; w++) {
            if (s.size() % w != 0) {
                continue;
            }
            bool p_found = true;
            for (int l=0; l+w <= s.size(); l+=w) {
                for (int i = 0; i < w; i++) {
                    if (s[i] != s[i+l]) {
                        p_found = false;
                    }
                }
            }
            if (p_found) {
                cout << w << endl;
                return true;
            }
        }

        return 0;
    }
};