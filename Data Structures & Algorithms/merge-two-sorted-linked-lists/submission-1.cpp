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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
         if(list1!=NULL && list2==NULL) return list1;
          if(list1==NULL && list2!=NULL) return list2;

        if(list1->val> list2->val)return mergeTwoLists(list2,list1);
        ListNode*f1=list1;
        ListNode* f2=list2;
        ListNode* s1= f1->next;

        while(s1!=NULL && f2!=NULL){
         if(s1->val > f2->val){
            ListNode* s2= f2->next;
            f1->next= f2;
            f2->next=s1;
            f1=f2;
            f2=s2;
         }
         else{
            f1=s1;
            s1=s1->next;
         }
        }

        if(f2!=NULL) f1->next=f2;   

return list1;
    }


};
