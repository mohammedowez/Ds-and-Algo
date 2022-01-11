int countNodesinLoop(struct Node *head)
{
    // Code here
    
    Node *slow=head;
    Node *fast=head;
    
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    } 
    
    if(slow!=fast)
        return 0;
        
    Node *curr=slow->next;
    
    int c=1;
    while(curr!=slow)
    {
        c++;
        curr=curr->next;
    } 
    
    return c;
}
