 
N = 4
value[] = {5,2,2,4}
Output: 5 2 4




Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     map<int,bool> mp;
     
     Node *curr=head;
     Node *pre=curr;
     
     while(curr!=NULL)
     {
         if(mp[curr->data])
         {
             pre->next=curr->next;
             delete(curr);
         } 
         else 
         {
             mp[curr->data]=1;
             pre=curr;
         } 
         
         curr=pre->next;
     }  
     
     return head;
     
     
     
     
    }
