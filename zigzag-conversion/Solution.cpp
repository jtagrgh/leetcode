// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        // Strings representing each row
        vector<string> rows(numRows, ""); 

        int i = 0;
        while (i < s.size()) {
            for (int j = 0; j < numRows && i < s.size(); j++) {
                rows[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j > 0 && i < s.size(); j--) {
                rows[j].push_back(s[i++]);
            }
        }
        
        // Concat final output string
        string out = "";
        for (const auto &s: rows) out += s;
        
        return out;
    }
};