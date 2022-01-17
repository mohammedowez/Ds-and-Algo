Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

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
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
            
        
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        
        
        ListNode *c1=l1,*c2=l2;
        
        while(c1 and c2)
        {
            if(c1->val<=c2->val)
            {
                curr->next=c1;
                curr=curr->next;
                c1=c1->next;
            } 
            
            else if(c1->val >=c2->val)
            {
                curr->next=c2;
                curr=curr->next;
                c2=c2->next;
            }
        } 
        
        if(c1)
        {
            curr->next=c1;
        } 
        
        if(c2)
        {
            curr->next=c2;
        } 
        
        return dummy->next;
        
    }
};
