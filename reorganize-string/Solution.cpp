// https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> m(26, 0);
        for (const char &c: s) {
            m[c-'a']++;
        }
        string out;
        char last = -1;
        while(1){
            int max = 0;
            char take = 0;
            for (int i = 0; i < m.size(); i++) {
                if (m[i] > 0 && i != last && m[i] > max) {
                    max = m[i];
                    take = 'a'+i;
                }
            }
            if (take != 0) {
                out.push_back(take);
                last = take-'a';
                m[take-'a']--;
            } else {
                break;
            }
        }
        // cout << out << endl;
        if (accumulate(m.begin(),m.end(),0) == 0) {
            return out;
        } else {
            return "";
        }
    }
};