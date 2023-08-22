// https://leetcode.com/problems/number-of-valid-clock-times

class Solution {
public:
    int countTime(string time) {
        int total = 0;
        if (time[0] != '?' && time[1] != '?') {
            total = 1;
        }
        else if (time[0] != '?') {
            if (time[0] - '0' == 2) {
                total = 4;
            } else {
                total = 10;
            }
        }
        else if (time[1] != '?') {
            if (time[1] - '0' < 4) {
                total = 3;
            } else {
                total = 2;
            }
        } else {
            total = 24;
        }
        
        if (time[3] != '?' && time[4] != '?') {
            total *= 1;
        }
        else if (time[3] != '?') {
            total *= 10;
        }
        else if (time[4] != '?') {
            total *= 6;
        } else {
            total *= 60;
        }
        
        return total;
    }
};