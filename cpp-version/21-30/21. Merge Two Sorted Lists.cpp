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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* t = head;
        while(l1 && l2){
            if(l1->val<l2->val){
                t->next = new ListNode(l1->val);
                t = t->next;
                l1 = l1->next;
            }else{
                t->next = new ListNode(l2->val);
                t = t->next;
                l2 = l2->next;
            }
        }
        while(l1){
            t->next= new ListNode(l1->val);
            t = t->next;
            l1 = l1->next;
        }
        while(l2){
            t->next = new ListNode(l2->val);
            t = t->next;
            l2 = l2->next;
        }
        return head->next;
    }
};