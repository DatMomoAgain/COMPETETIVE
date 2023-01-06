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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(k==1 || head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* tail = head;

        for(int i=0; i<k-1; i++)
        {
            tail = tail->next;
            if(tail==NULL)
                return head;
        }
        head = tail;

        while(true)
        {
            temp2=tail->next;
            reverse(temp,tail);
            ListNode* temp3 = temp2;

            for(int i=0; i<k-1; i++)
            {
                if(temp2==NULL)
                {
                    temp->next = temp3;
                    return head;
                }

                temp2 = temp2->next;
                
                if(temp2==NULL)
                {
                    cout<<temp->val;
                    temp->next = temp3;
                    return head;
                }
            }
            temp->next = temp2;
            tail = temp2;
            temp = temp3;
        }
        return head;
    }

    //will reverse but 1st node will point to NULL
    void reverse(ListNode* head, ListNode* tail)
    {
        if(head->next == NULL)
        {
            return;
        }
        else if(head==NULL || head==tail)
        {
            return;
        }

        ListNode* tailn = tail->next;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp3 = head->next->next;
        temp1->next = NULL;

        while(temp2 != tailn)
        {
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            if(temp3!=NULL)
                temp3 = temp3->next;
            else
                break;
        }

    }
};
