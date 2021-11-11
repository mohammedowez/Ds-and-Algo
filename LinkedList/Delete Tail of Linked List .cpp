Node * deleteTail(Node *head)
{
    //Your Code here
    if(head==NULL)
        return NULL;
    
    Node *curr=head;    
    while(curr->next->next!=NULL)
        curr=curr->next;
        
    delete curr->next;
   curr->next=NULL;
    return head;
}
