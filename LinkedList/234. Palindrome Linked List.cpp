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
    
    ListNode *reverse(ListNode *head1)
    {
        ListNode *curr=head1,*pre=NULL,*nxt=NULL;
        
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        } 
        head1=pre;
        return head1;
    }
    
    ListNode *mid(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        } 
        
        return slow;
    }
  
    
    bool isPalindrome(ListNode* head) 
    {
        
        
        ListNode *temp=mid(head);
        
        ListNode *currr=reverse(temp);
        
        ListNode *t=head;
        
        
        while(currr!=NULL)
        {
            if(t->val!=currr->val)
                return 0;
            
            currr=currr->next;
            t=t->next;
        }
        return 1;
        
    }
};
