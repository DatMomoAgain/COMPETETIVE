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
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* current = head;
        ListNode* net = head->next;
        
        while(net != NULL)
        {
            if(current->val == net->val)
            {
                while(current->val==net->val)
                {
                    net = net->next;
                    if(net ==NULL)
                    {
                        break;
                    }
                }
                current->next = net;
                current = net;
                if(net){
                net = net->next;}
                continue;
            }
            net = net->next;
            current = current->next;
        }
        return head;
    }
};
