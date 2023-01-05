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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2 = head;

        if(head==NULL)
            return head;

        int i = 0;

        while(temp->next!=NULL && temp!=NULL)
        {
            //1->2->3->4
            temp = temp->next;
            temp2->next = temp->next;
            temp->next = temp2;
            //2->1->3->4

            i++;
            if(i==1)
            {
                head = temp;
            }       

            if(temp2->next == NULL)
                break;

            ListNode* temp3 = temp2->next;
            
            //2->1->3->4
            if(temp2->next->next!=NULL)
            {
                temp2->next = temp2->next->next;
            }
            //2->1->4<-3
            temp = temp3;
            temp2 = temp3;
        }

        return head;
    }
};
