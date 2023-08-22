// https://leetcode.com/problems/two-sum


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        for index_1, num in enumerate(nums):
            complement = target - num
            
            if (complement in nums):
                if (index_1 == nums.index(complement)): continue
                return [index_1, nums.index(complement)]
            
            
            
                
                