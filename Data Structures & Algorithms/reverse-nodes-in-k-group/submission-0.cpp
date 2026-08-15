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
ListNode* kthnode(ListNode*curr,int k){
    while(curr!=NULL && k>0){
        curr=curr->next;
        k--;
    }
return curr;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy= new ListNode(0,head);
        ListNode* g_prev= dummy;

        while(true){
ListNode* kth= kthnode(g_prev,k);
if(!kth)break;
ListNode* g_next=kth->next;
ListNode* prev= kth->next;
ListNode* curr=g_prev->next;
while(curr!=g_next){
    ListNode* nxt= curr->next;
    curr->next= prev;
    prev=curr;
    curr= nxt;
}
ListNode* tmp= g_prev->next;
g_prev->next=kth;
g_prev=tmp;

        }
        return dummy->next;
    }
};
