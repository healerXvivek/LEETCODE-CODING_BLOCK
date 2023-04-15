/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA,* b=headB;
        while(a!=b){
            if(a==NULL)
            a=headB;
            else
            a=a->next;

            if(b==NULL)
            b=headA;
            else
            b=b->next;
        }
        return a;
    }
};


//method 2:-
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        ListNode*temp=headA;
        while(temp)
        {
            s.insert(temp);
            temp=temp->next;
        }
        ListNode* temp1=headB;
        while(temp1)
        {
            if(s.find(temp1)!=s.end())
            {
                return temp1;
            }
            temp1=temp1->next;
        }
        return NULL;
    }
};
