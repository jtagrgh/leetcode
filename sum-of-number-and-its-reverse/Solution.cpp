// https://leetcode.com/problems/sum-of-number-and-its-reverse

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i ++) {
            int n = i;
            int rev = 0, rem;
            while (n != 0) {
                rem = n % 10;
                rev = rev * 10 + rem;
                n /= 10;
            }
            if (i + rev == num) return true;
        }
        return false;
    }
};