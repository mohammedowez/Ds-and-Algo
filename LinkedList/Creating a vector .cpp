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
    ListNode* swapNodes(ListNode* head, int k) {
        
        
        vector<ListNode*> v;
        ListNode *curr=head;
        
        while(curr)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        
        int c=0;
        
        for(int i=0;i<v.size();i++)
        {
            c++;
            if(c==k)
            {
                swap(v[i],v[v.size()-k]);
                break;
            }
        } 
        
        curr=head;
        int i=0;
        
        while(curr!=NULL)
        {
            curr->val=v[i];
            curr=curr->next;
            i++;
        }
        
        return head;
    }
};
