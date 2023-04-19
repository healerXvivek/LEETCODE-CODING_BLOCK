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
    ListNode* reverseL(ListNode* head){
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

    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* nhead=reverseL(head);
        stack<int> s;
        vector<int> ans;
        s.push(nhead->val);
        nhead=nhead->next;
        ans.push_back(0);
        while(nhead){
            while(!s.empty() && s.top()<=(nhead->val)){
                s.pop();
            }
            int k=s.empty() ? 0 : s.top();
            ans.push_back(k);
            s.push(nhead->val);
            nhead=nhead->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
