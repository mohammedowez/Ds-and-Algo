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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)
            return head;
        ListNode *tmp=head,*age;
        int count=1;
        while(tmp && count<left)
        {
            age=tmp;
            tmp=tmp->next;
            count++;
        }
        ListNode *prev=NULL,*nxt=NULL,*curr=tmp;
        while(curr && count<=right)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
        if(left==1)
        {
            head=prev;
        }
        else
        {
            age->next=prev;
        }
     //   cout<<tmp->val<<" "<<curr->val;
        tmp->next=curr;
        return head;
    }
};
