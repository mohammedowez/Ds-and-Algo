Input: head = [1,2,3,4]
Output: [1,4,2,3]

class Solution 
{
public:
    
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr=head,*pre=NULL,*nxt=NULL;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        } 
        
        return pre;
        
    }
    
    void reorderList(ListNode* head) 
    {
        
        // Finding the Middle element of LInkedList 
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        } 
        
        ListNode *first=head;
        
        
        // from the midlle reverse the LinkedList 
        ListNode *second=reverse(slow->next);
        slow->next=NULL;
        
        // start from the second and end till it will not become end
        while(second)
        {
            ListNode *temp1=first->next;
            ListNode *temp2=second->next;
            
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        } 
    
        
    }
};
