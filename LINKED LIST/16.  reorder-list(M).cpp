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
            ListNode* prev=NULL;
            while(curr){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }

    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverse(slow->next);
        slow->next=NULL;
        ListNode* first=head;
        
        while(second){
            ListNode* curr1=first->next;
            ListNode* curr2=second->next;
            first->next=second;
            second->next=curr1;
            first=curr1;
            second=curr2;
        }
    }
};
