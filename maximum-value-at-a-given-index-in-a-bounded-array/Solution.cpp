// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        size_t n_left = index;
        size_t n_right = n - index - 1;

        auto getMinSum = [&](size_t x) {
            size_t k = x-1;
            long long int p_left = k - n_left;
            long long int p_right = k - n_right;
            size_t sum = 0;
            sum += x;
            sum += 2*(k*(k+1)/2);
            if (p_left > 0) { 
                sum -= p_left*(p_left+1)/2;
            } else {
                sum += abs(p_left);
            }
            if (p_right > 0) { 
                sum -= p_right*(p_right+1)/2;
            } else {
                sum += abs(p_right);
            }
            return sum;
        };

        size_t bound_l = 1;
        size_t bound_u = maxSum+1;
        size_t m;
        while (bound_l < bound_u-1) {
            m = (bound_l + bound_u) / 2;
            if (getMinSum(m) > maxSum) {
                bound_u = m;
            } else {
                bound_l = m;
            }
        }
        
        return bound_l;
    }
};