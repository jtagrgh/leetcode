// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        auto frames = stack<ListNode*>{};
        
        ListNode* seeker = head;
        while(seeker != nullptr) {
            frames.push(seeker);
            seeker = seeker->next;
        }
        
        int carry = 0;
        while (!frames.empty()) {
            int new_value = frames.top()->val * 2 + carry;
            frames.top()->val = new_value % 10;
            carry = new_value / 10;
            frames.pop();
        }
        
        if (carry > 0) {
            return new ListNode(carry, head);
        } else {
            return head;
        }
    }
};