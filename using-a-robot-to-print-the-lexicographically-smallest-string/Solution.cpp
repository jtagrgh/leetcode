// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string

class Solution {
public:
    string robotWithString(string s) {
        string robo;
        string paper;
        
        /* Generate a mapping of letters to their
            frequency in s */
        map<char, int> counts;
        for (auto &c: s) {
            if (counts.find(c) == counts.end()) {
                counts[c] = 1;
            }
            else {
                counts[c]++;   
            }
        }
        
        /* Main logic */
        for (auto l = s.begin(); l != s.end(); l++) {
            char d = *l;
            robo.push_back(d);
            counts[d]--;
            if (counts[d] == 0) counts.erase(d);
            char best = (*counts.begin()).first;
            /* Pop from robo stack until there exists
            /* a remaining letter in s thats smaller than the
            /* top of the stack,, meaning we should stack more */
            while (robo.size() > 0 && robo.back() <= best) {
                paper.push_back(robo.back());
                robo.pop_back();
            }
        }
        
        /* Clear any left in the robo stack */
        while (robo.size() > 0) {
            paper.push_back(robo.back());
            robo.pop_back();
        }

        return paper;
        
    }
};