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
    int getlength(ListNode*head)
    {
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
        }
 
        return len;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int listlength=getlength(head);
        int partsize=listlength/k;
        int extranodes=listlength%k;
        vector<ListNode*> ans;
        ListNode*curr=head,*prev=NULL;
        while(head)
        {
            int eachpartsize=partsize;
            ans.push_back(curr);
            while(eachpartsize>0)
            {
                prev=curr;
                curr=curr->next;
                eachpartsize--;
            }
            if(extranodes!=0 && curr!=NULL)
            {
                extranodes--;
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL)
            {
                head=curr;
                prev->next=NULL;
            }
        }
        while(ans.size()!=k)
            ans.push_back(NULL);
        return ans;
    }
};



// method 2:-


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int length = 0;
        ListNode *curr = head;

        while(curr!=NULL){
            length++;
            curr = curr->next;
        }

        vector<ListNode*> ans;
        curr = head;

        if(k>=length){
            
            while(curr!=NULL){
                ListNode *temp = curr->next;
                curr->next = NULL;
                ans.push_back(curr);
                curr = temp;
            }

            int y = k-length;
  
            while(y>0){
                ans.push_back(NULL);
                y--;
            }
        }

        else{

            int minSize = length/k;
            int rem = length%k;

            while(k>0 && curr!=NULL){

                int m = 0;
                if(rem>0){
                    m = minSize + 1;
                    rem--;
                }
                else{
                    m = minSize;
                }

                head = curr;

                for(int i=1; i < m && curr->next!=NULL; i++){
                    curr = curr->next;
                } 

                if(curr->next!=NULL){
                    ListNode *temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                    ans.push_back(head);
                }
                else
                {
                    ans.push_back(head);
                }
                k--;
            }
        }
        return ans;
    }
};
