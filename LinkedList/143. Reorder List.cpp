Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


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
    void reorderList(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
            return;
        
        vector<int> v,v1;
        ListNode *curr=head;
        while(curr!=NULL)
        {
        	v.push_back(curr->val);
        	curr=curr->next;
		} 
		
		int i,n=v.size();
		for(i=0;i<n/2;i++)
		{
			v1.push_back(v[i]);
			v1.push_back(v[n-i-1]);
		} 
		
		if(n%2!=0)
			v1.push_back(v[i]);
		
		curr=head;
		i=0;
		while(curr!=NULL)
		{
			curr->val=v1[i];
			curr=curr->next;
			i++;
		} 
    }
};
