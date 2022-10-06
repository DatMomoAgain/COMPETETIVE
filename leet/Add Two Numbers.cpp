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
    int count(ListNode* l1)
    {
        int i=0;
        ListNode* temp = l1;
        while(temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        
        return i;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c1 = count(l1);
        int c2 = count(l2);
        int x;
        ListNode* temp;
        if (c1 >= c2)
        {
            c1 = c1;
        }
        else
        {
            x = c1;
            c1 = c2;
            c2 = x;
            temp = l2;
            l2 = l1;
            l1 = temp;
        }
        int n1=0;
        int carry=0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode();
        ListNode* t3 = ans;
        for(int i=0; i<c1; i++)
        {
            if (i<c2){
                n1 = temp1->val + temp2->val + carry;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                n1 = temp1->val + carry;
                temp1 = temp1->next;
            }
            carry = n1/10;
            n1 = n1%10;
            t3->val = n1;
            if (i != c1-1)
            {
                t3->next = new ListNode();
                t3 = t3->next;
            }
        }
        if(carry !=0)
        {
            t3->next = new ListNode();
            t3->next->val = carry;
            t3->next->next = NULL;
        }
        return ans;
        
    }
};
