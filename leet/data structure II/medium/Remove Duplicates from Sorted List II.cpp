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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2 = head;

        //if no node or 1 node
        if(head==NULL)
            return head;
        else if(head->next==NULL)
            return head;
        
        temp = temp->next;

        //if starting nodes are same
        while(head->val==head->next->val){
            while(head->val==head->next->val)
            {
                head = head->next;
                if(head->next==NULL)
                    return NULL;
            }
            head = head->next;
            if(head->next==NULL)
                return head;
        }

        temp2= head;
        temp = head->next;

        //normal case
        while(temp->next!=NULL)
        {
            int c=0;
            if(temp->val==temp->next->val)
            {
                while(temp->val==temp->next->val)
                {
                    temp=temp->next;
                    if(temp->next==NULL)
                    {
                        temp2->next=NULL;
                        return head;
                    }
                }
                temp = temp->next;
                temp2->next = temp;
                c++;
            }
            if (c==0){
            temp = temp->next;
            temp2 = temp2->next;
            }
        }

        return head;
    }
};
