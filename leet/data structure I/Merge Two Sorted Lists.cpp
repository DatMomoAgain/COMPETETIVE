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
    ListNode* sort(ListNode* head, int length)
    {
        ListNode* temp = head->next;
        int max = head->val;
        ListNode* nmax = head; //node with max value
        int t;//to swap
        for(int i=length; i>1; i--)
        {
            for(int j=0; j<i-1; j++)
            {
                if(temp->val > max)
                {
                    max = temp->val;
                    nmax = temp;
                }
                //makes sure doesnt temp doesnt go beyond last node
                if(j!=i-2)
                {
                    temp = temp->next;
                }
            }
            //by this time temp points at last node
            //swapping happens here
            t = temp->val;
            nmax->val = t;
            temp->val = max;       
            
            //reinitialize variables
            temp = head->next;            
            max = head->val;
            nmax = head;
        }
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL)
        {
            return list1;
        }
        else if(list1 == NULL && list2 != NULL)
        {
            return list2;
        }
        else if(list1 != NULL && list2 == NULL)
        {
            return list1;
        }
        
        int q=1, w=1;
        ListNode* temp = list1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            q++;
        }
        ListNode* temp2 = list2;
        while(temp2->next!=NULL)
        {
            temp2 = temp2->next;
            w++;
        }
        temp->next = list2;       
        
        int length = w+q;
        
        return sort(list1, length);
    }
};
