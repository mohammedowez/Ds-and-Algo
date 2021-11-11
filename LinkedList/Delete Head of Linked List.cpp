Node * deleteHead(Node *head)
{
    //Your code here
    
    if(head==NULL)
        return NULL;
    Node *temp=head->next;
    delete head;
    
    return temp;

}
