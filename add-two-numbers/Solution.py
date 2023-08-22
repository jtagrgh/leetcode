// https://leetcode.com/problems/add-two-numbers

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        dummyHead = ListNode()
        p = l1
        q = l2
        curr = dummyHead
        
        carry = 0
        
        while (p is not None or q is not None):
            x = p.val if p != None else 0
            y = q.val if q != None else 0
            n_sum = carry + x + y
            
            carry = n_sum // 10
            curr.next = ListNode(n_sum % 10)
            curr = curr.next
            
            if (p is not None): p = p.next
            if (q is not None): q = q.next
                
        if (carry > 0):
            curr.next = ListNode(carry)
            
        return dummyHead.next;
            
        
        
        
        
        
            
        
            