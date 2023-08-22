// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s_map;
        map<char, char> t_map;
        list<int> s_iso;
        list<int> t_iso;
        
        int itr = 0;
        for (const auto &c: s) {
            if (s_map.find(c) == s_map.end()) s_map[c] = itr++;
            s_iso.push_back(s_map[c]);
        }
        itr = 0;
        for (const auto &c: t) {
            if (t_map.find(c) == t_map.end()) t_map[c] = itr++;
            t_iso.push_back(t_map[c]);
        }
        
        return (s_iso == t_iso);
    }
};