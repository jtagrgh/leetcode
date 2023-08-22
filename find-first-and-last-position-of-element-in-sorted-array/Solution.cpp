// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
    
    int lower_bound(vector<int> &nums, int target, int l, int r) {
        if (l == r) return -1;
        int midex = (l+r)/2;
        if (nums[midex] == target) {
            if (midex == 0 || nums[midex-1] != target) {
                return midex;
            }
            return lower_bound(nums, target, l, midex);
        }
        else if (nums[midex] < target) {
            return lower_bound(nums, target, midex+1, r);
        }
        else if (nums[midex] > target) {
            return lower_bound(nums, target, l, midex);
        }
        return -1;
    }
    
    int upper_bound(vector<int> &nums, int target, int l, int r) {
        if (l == r) return -1;
        int midex = (l+r)/2;
        if (nums[midex] == target) {
            if (midex == nums.size() - 1 || nums[midex+1] != target) {
                return midex;
            }
            return upper_bound(nums, target, midex+1, r);
        }
        else if (nums[midex] < target) {
            return upper_bound(nums, target, midex+1, r);
        }
        else if (nums[midex] > target) {
            return upper_bound(nums, target, l, midex);
        }
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1,-1};
        
        return vector<int> {lower_bound(nums, target, 0, nums.size()), 
                            upper_bound(nums, target, 0, nums.size())};
        
    }
};