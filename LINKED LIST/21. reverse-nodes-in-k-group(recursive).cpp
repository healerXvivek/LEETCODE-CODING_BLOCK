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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (count < k) {
            ListNode* temp = NULL;
            while (count > 0) {
                temp = prev->next;
                prev->next = curr;
                curr = prev;
                prev = temp;
                count--;
            }
            return curr;
        }
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};



// method 2:-

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int flag = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            flag++;
            temp = temp->next;
        }
        
        if(flag<k){
            return head;
        }
        if(head == NULL){
            return NULL;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while(curr!=NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next!= NULL){
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};
