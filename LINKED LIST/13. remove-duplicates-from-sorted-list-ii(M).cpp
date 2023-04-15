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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        map<int,int> m;
        while(temp){
            m[temp->val]++;
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        for(auto i : m){
            if(i.second<2){
                ListNode* n=new ListNode(i.first);
                ans->next=n;
                ans=n;
            }
        }
        return dummy->next;
    }
};
