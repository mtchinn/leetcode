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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int>mstack;
        ListNode* ret = new ListNode(0);
        ListNode* t = ret;
        while(head){
            mstack.push(head->val);
            head = head->next;
            if(mstack.size()==k){
                while(!mstack.empty()){
                    t->next = new ListNode(mstack.top());
                    t = t->next;
                    mstack.pop();
                }
            }
        }
        stack<int>ts;
        while(!mstack.empty()){
            int num =mstack.top();
            ts.push(num);
            mstack.pop();
        }
        while(!ts.empty()){
            t->next = new ListNode(ts.top());
            t = t->next;
            ts.pop();
        }
        return ret->next;
    }
};