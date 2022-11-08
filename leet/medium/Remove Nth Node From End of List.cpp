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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL)
            return head;
        ListNode* temp = head;
        int c=0;
        while(temp!=NULL)
        {
            temp = temp->next;
            c++;
        }
        if(c==1)
            return NULL;
        c-=n;
        temp = head;
        if(c==0){
            head = head->next;
            return head;
        }
        for(int i=0; i<c-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
