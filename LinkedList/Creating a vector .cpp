class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        vector<int> v;
        
        ListNode *curr=head;
        
        while(curr!=NULL)
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
            
                swap(v[i],v[v.size()-1-i]);
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
