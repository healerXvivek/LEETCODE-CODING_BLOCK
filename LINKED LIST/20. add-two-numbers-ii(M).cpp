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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nl1=reverse(l1);
        ListNode* nl2=reverse(l2);
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        int carry=0,sum=0;
        while(nl1 && nl2){
            sum=(nl1->val) + (nl2->val) +carry;
            carry=sum/10;
            int d=sum%10;
            ListNode* temp=new ListNode(d);
            tail->next=temp;
            tail=tail->next;
            nl1=nl1->next;
            nl2=nl2->next;
        }
         while(nl1){
            sum=(nl1->val) + carry;
            carry=sum/10;
            int d=sum%10;
            ListNode* temp=new ListNode(d);
            tail->next=temp;
            tail=tail->next;
            nl1=nl1->next;
        }
        while(nl2){
            sum=(nl2->val) + carry;
            carry=sum/10;
            int d=sum%10;
            ListNode* temp=new ListNode(d);
            tail->next=temp;
            tail=tail->next;
            nl2=nl2->next;
        }
        if (carry != 0){
            ListNode* temp=new ListNode(carry);
            tail->next=temp;
            tail=tail->next;
        }
        tail->next=NULL;
        return (reverse(dummy->next));
    }
};
