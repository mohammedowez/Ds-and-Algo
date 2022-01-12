Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        
        ListNode *dummy= new ListNode(0);
        ListNode *curr=dummy;
        
        while(head)
        {
            if(head->next && head->val==head->next->val)
            {
                while(head->next && head->val==head->next->val)
                    head=head->next;
            } 
            else 
            {
                curr->next=head;
                curr=head;
            } 
            
            head=head->next;
            
        } 
        
        curr->next=NULL;
        return dummy->next;
        
    }
};
