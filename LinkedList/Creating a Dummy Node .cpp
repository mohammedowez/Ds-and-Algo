





class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        ListNode *d1=new ListNode(0);
        ListNode *d2=new ListNode(0);
        
        ListNode *t1=d1;
        ListNode *t2=d2;
        
        int i=0;
        ListNode *curr=head;
        
        while(curr!=NULL)
        {
            if(i%2==0)
            {
                t1->next=curr;
                t1=t1->next;
            } 
            else 
            {
                t2->next=curr;
                t2=t2->next;
            } 
            curr=curr->next;
            i++;
            
        } 
        
        t2->next=NULL;
        t1->next=d2->next;
        
        return d1->next;
        
        
    }
};
