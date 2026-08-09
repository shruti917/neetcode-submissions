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
    void reorderList(ListNode* head) {

         if (!head || !head->next) return;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow= slow->next;
            fast=fast->next->next;
        }

        ListNode* curr=slow->next;
        slow->next = nullptr;
        ListNode* prv = nullptr;

        while(curr){
            ListNode* nxt= curr->next;
            curr->next= prv;
            prv=curr;
            curr=nxt;
        }

        ListNode* first= head;
        ListNode* second= prv;

        while(second){
             ListNode* firstNode= first->next;
             ListNode* secondNode= second->next;
            first->next= second;
            second->next= firstNode;

            first=firstNode;
            second= secondNode;

        }

    }
};


