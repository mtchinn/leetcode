//很气啊，看的题目时说是给出的链表是转置的，一开始就想着要用栈什么的存blabla的，结果代码又臭又长，其实完全没必要....
//俩个链表相加，输入的链表转置的，也就是个位数在前。相加之后，仍按照个位在前输出结果链表。
#include<iostream>
#include<vector>
#include <stack>
#include <queue>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret;
        queue<int>q1,q2,q;
        while(l1!=NULL){
            q1.push(l1->val);
            l1 = l1->next;
        }
        //cout<<"s1 size "<<s1.size()<<endl;
        while(l2!=NULL){
            q2.push(l2->val);
            l2 = l2->next;
        }
        int jinzhi = 0;
        while(!q1.empty() || !q2.empty()){
            int num = 0;
            if(q1.empty()){
                num = q2.front()+jinzhi;
                q2.pop();
            }else if(q2.empty()){
                num = q1.front() + jinzhi;
                q1.pop();
            }else{
                num = q1.front() + q2.front() + jinzhi;
                q1.pop();
                q2.pop();
            }
            q.push(num%10);
            jinzhi = num/10;
        }
        while(jinzhi){
            q.push(jinzhi%10);
            jinzhi/=10;
        }
        ret = new ListNode(q.front());
        q.pop();
        ListNode* node = ret;
        //ret = ret->next;
        while(!q.empty()){
            ret->next = new ListNode(q.front());
            q.pop();
            ret = ret->next;
        }
        return node;
    }

    void printLink(ListNode* node){
        while(node!=NULL){
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
    }
};