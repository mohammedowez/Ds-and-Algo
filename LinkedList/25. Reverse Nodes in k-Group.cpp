Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // check and return head
        ListNode *node = head;
        for(int i = 0; i < k; i++)
        {
            if(!node) 
                return head;
            node = node->next;
        }
        
        //reverse the linkedlist 
        ListNode *cur = head, *prev = NULL, *nex = NULL;        
        for(int i = 0; i < k; i++)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
       
       // from current pointer to next node 
       head->next=reverseKGroup(cur, k);
        return prev;
    }
};
