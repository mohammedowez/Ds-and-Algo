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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        
        if(k==0 or head==NULL)
            return head;
        
//calculating length of list
        int cnt=1;
        ListNode *curr=head;
        while(curr->next)
        {
            cnt++;
            curr=curr->next;
        }

 // Point the length of a list to head so that the cycle occures      
        curr->next=head;
/* 
//making k less than the size of linked list
        k = k%size;
        // checking how many elements should be sent forward 
        k = size-k;
*/
        cout<<curr->val<<" ";
        int rotate=(cnt-(k%cnt));
        
        
        while(rotate--)
            curr=curr->next;
        
        cout<<curr->val;
// point the curr of next to head and make the curr of next to NULL      
        head=curr->next;
        
        curr->next=NULL;
            
        return head;
        
        
    }
};
