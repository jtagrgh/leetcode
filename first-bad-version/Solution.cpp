// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned r = n;
        unsigned l = 0;
        unsigned first_bad;
        
        while (l <= r) {
            unsigned mid = floor((l+r)/2);
            if (isBadVersion(mid)) {
                first_bad = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return first_bad;
    }
};