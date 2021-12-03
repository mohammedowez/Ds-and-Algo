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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        
        
        vector<ListNode*> v;
        ListNode *curr=head;
        
        while(curr!=NULL)
        {
            v.push_back(curr);
            curr=curr->next;
        }
        
        int temp=v[k-1]->val;
        int end=v[v.size()-k]->val;
        v[v.size()-k]->val=temp;
        v[k-1]->val=end;
        
        return head;
        
        
    }
};
