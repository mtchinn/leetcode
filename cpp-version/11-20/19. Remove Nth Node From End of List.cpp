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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hh = new ListNode(0);
        hh->next = head;
        ListNode* pre = hh;
        ListNode* rear = hh;
        ++n;
        while(--n && pre)
            pre = pre->next;
        if(n>0 ) return NULL;

        while(pre->next!=NULL){
            pre = pre->next;
            rear = rear->next;
        }
        if(hh == rear) return head->next;
        if(rear == NULL || rear->next == NULL) return NULL;
        rear->next = rear->next->next;
        return head;
    }
};