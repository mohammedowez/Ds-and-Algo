void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        struct Node *fast = head;
        struct Node *slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        if(slow == head)
        {
            while(slow->next != fast)
                    slow = slow->next;
            slow->next = NULL;
        }
        else if(slow==fast)
        {
            slow=head;
            while(slow->next != fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
            
        }
        
        
    }
