// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *t = head, *h = head;
        while (h != NULL) {
            if (h->next == NULL) return NULL;
            t = t->next;
            h = h->next->next;
            if (h == t) {
                h = head;
                while (h != t) {
                    h = h->next;
                    t = t->next;
                }
                return h;
            }
        }
        return NULL;
    }
};