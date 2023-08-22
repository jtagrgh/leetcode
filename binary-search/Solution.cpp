// https://leetcode.com/problems/binary-search

class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int target) {
        if (l == r) return -1;
        int mid = (l+r)/2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (target > nums[mid]) {
            return bs(nums, mid+1, r, target);
        }
        else {
            return bs(nums, l, mid, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size(), target);
    }
};