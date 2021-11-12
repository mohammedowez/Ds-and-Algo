struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *curr,*next,*pre;
        curr=head;
        pre=NULL;
        
        while(curr!=NULL)
        {
            next=curr->next;
            
            curr->next=pre;
            
            pre=curr;
            curr=next;
            
        } 
        
        head=pre;
        
        return head;
        
        
    }
