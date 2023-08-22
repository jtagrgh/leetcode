// https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array

class Solution {
public:
    int minimumSum(int n, int k) {
        int m = k/2;
        if (m>=n) {
            return (n*(n+1))/2;
        } else {
            int sum = (m*(m+1))/2;
            int l = n-m;
            sum += ((k+l-1)*(k+l))/2;
            sum -= ((k-1)*(k))/2;
            return sum;
        }
    }
};