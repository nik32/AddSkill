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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *ans_head = NULL, *pri = NULL, *new_node;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                new_node = new ListNode(l1->val, NULL);
                l1 = l1->next;
            }
            else
            {
                new_node = new ListNode(l2->val, NULL);
                l2 = l2->next;
            }
            
            if(ans_head == NULL)
                ans_head = new_node;
            else
                pri->next = new_node;
            
            pri = new_node;
        }
        
        while(l1 != NULL)
        {
            ListNode *new_node = new ListNode(l1->val, NULL);
            
            if(ans_head == NULL)
                ans_head = new_node;
            else
                pri->next = new_node;
            
            pri = new_node;
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            ListNode *new_node = new ListNode(l2->val, NULL);
            
            if(ans_head == NULL)
                ans_head = new_node;
            else
                pri->next = new_node;
            
            pri = new_node;
            l2 = l2->next;
        }
        
        return ans_head;
    }
};
