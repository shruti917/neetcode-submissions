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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;

        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while(l1 || l2 || carry){
            int left=0,right=0;
            if(l1!=NULL) left= l1->val;
            if(l2!=NULL) right= l2->val;

            int sum= left+right+carry;
            int digit= sum%10;
            temp->next= new ListNode(digit);

            carry= sum/10;
temp= temp->next;
if(l1!=NULL) l1= l1->next;
            if(l2!=NULL) l2= l2->next;

        }
        return ans->next;
    }
};
