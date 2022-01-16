
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]


class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        
        if(head==NULL or head->next==NULL or head->next->next==NULL)
        {
            return head;
        } 
        
        ListNode *evenLink=head->next;
        ListNode *even=head->next;
        ListNode *odd=head;
        
         while(odd->next && even->next) 
         {
             odd->next=odd->next->next;
             even->next=even->next->next;
             odd=odd->next;
             even=even->next;
         }
          odd->next=evenLink;
        return head;
        
    }
};
