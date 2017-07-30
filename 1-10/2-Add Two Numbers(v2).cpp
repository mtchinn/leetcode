/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 反正从个位开始计算，也是各位输出，可以直接点计算，参考了discuss
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        int jz = 0;
        while(l1 || l2 || jz){
            int sum = (l1?l1->val:0)+ (l2?l2->val:0) + jz;
            p->next = new ListNode(sum%10);
            jz = sum/10;
            p = p->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return head->next;
    }
};