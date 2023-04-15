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
    ListNode* partition(ListNode* head, int x) {
        ListNode* more=new ListNode(0);
        ListNode* moretail=more;
        ListNode* less=new ListNode(-0);
        ListNode* lesstail=less;
        ListNode* curr=head;
        while(curr){
            if(curr->val < x){
                lesstail->next=curr;
                lesstail=lesstail->next;
            }
            else{
                moretail->next=curr;
                moretail=moretail->next;
            }
            curr=curr->next;
        }
        moretail->next=NULL;
        lesstail->next=more->next;
        return less->next;
    }
};
