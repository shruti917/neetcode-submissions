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


ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prv=NULL;

    while(curr){
        ListNode* nxt= curr->next;
        curr->next=prv;
        prv=curr;
        curr= nxt;
    }
    return prv;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {

    
        ListNode* rev = reverse(head);
        ListNode* head1= rev;

            if (n == 1) {
        rev = rev->next;
        return reverse(rev);
    }
        


ListNode*prv= rev;

    for (int i = 1; i < n - 1; i++) {
        prv = prv->next;
    }

    prv->next = prv->next->next;


        
        return reverse(head1);

    }
};

