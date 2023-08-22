// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }

        const int w = needle.size();

        size_t hash_h = accumulate(
            haystack.begin(),
            haystack.begin() + w,
            size_t{0}
        );

        size_t hash_n = accumulate(
            needle.begin(),
            needle.end(),
            size_t{0}
        );

        if (hash_h == hash_n) {
            if (haystack.substr(0, w) == needle) {
                return 0;
            }
        }

        for (int l = 0; l+w < haystack.size(); l++) {
            hash_h -= haystack[l];
            hash_h += haystack[l+w];

            if (hash_h == hash_n) {
                if (haystack.substr(l+1, w) == needle) {
                    return l+1;
                }
            }
        }

        return -1;
    }
};