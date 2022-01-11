/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> sett;
        
        ListNode *dummy=head;
        
        while(dummy!=NULL)
        {
            if(sett.find(dummy)!=sett.end())
            {
                return 1;
            } 
            sett.insert(dummy);
            dummy=dummy->next;
        }
         
        return 0;
            
    }
};
