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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr=head;
        int cnt=0;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        curr=head;
        ListNode* odd = new ListNode(-1);
        ListNode* oddtail = odd;
        ListNode* even = new ListNode(-1);
        ListNode* eventail = even;
        for(int i=1;i<=cnt;i++){
            if(i%2==0){
                eventail->next=curr;
                eventail=curr;
            }
            else{
                oddtail->next=curr;
                oddtail=curr;
            }
            curr=curr->next;
        }
        oddtail->next=even->next;
        eventail->next=NULL;
        return odd->next;
    }
};


//method 2:-

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = NULL, *headodd = NULL, *even = NULL, *headeven = NULL;
        if(!head || !head->next || !head->next->next) 
        return head;
        odd = head; headodd = odd;
        even = head->next; headeven = even;
        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = headeven;
        return headodd;
    }  
};
