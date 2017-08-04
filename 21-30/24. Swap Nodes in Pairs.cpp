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
    ListNode* swapPairs(ListNode* head) {
        ListNode* h =  new ListNode(0);
        h->next = head;
        while(head) {
            ListNode *hh = head->next?head->next:NULL;
            if(hh == NULL) break;
            head->val = head->val +hh->val;
            hh->val = head->val - hh->val;
            head->val = head->val - hh->val;
            head = head->next->next;
        }
        return h->next;
    }
};