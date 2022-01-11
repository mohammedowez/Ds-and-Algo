Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *l3=new ListNode(0);
        ListNode *curr=l3;
        
        int carry=0;
        int s1=0,s2=0;
        while(l1 || l2 || carry)
        {
            if(l1!=NULL)
            {
                carry+=l1->val;
                l1=l1->next;
            }
             if(l2!=NULL)
            {
                carry+=l2->val;
                l2=l2->next;
            } 
            
            curr->next=new ListNode(carry%10);
            curr=curr->next;
            carry=carry/10;
        } 
        
        return l3->next;
        
    }
};
