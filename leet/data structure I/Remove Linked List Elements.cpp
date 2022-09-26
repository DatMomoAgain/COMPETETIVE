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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(temp != NULL)
        {
            if(temp==head && temp->val==val)
            {
                temp = temp->next;
                head = head->next;
                continue;
            }
            
            if (temp->val==val && temp->next!=NULL)
            {
                while(temp2->next!=temp)
                {
                    temp2 = temp2->next;
                }
                temp = temp->next;
                temp2->next = temp;
                continue;
            }
            else if(temp->val==val && temp->next==NULL)
            {
                while(temp2->next!=temp)
                {
                    temp2 = temp2->next;
                }
                temp2->next = NULL;
                //continue;
            }
            temp = temp->next;
        }
        
        return head;        
    }
};
