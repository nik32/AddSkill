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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *ans_head = NULL, *pri = NULL;
        
        while(l1 != NULL && l2 != NULL)
        {
            ListNode *new_node = new ListNode((l1->val + l2->val + carry) % 10, NULL);
            carry = (l1->val + l2->val + carry) >= 10 ? 1 : 0;
            
            if(ans_head == NULL)
                ans_head = new_node;
            else
                pri->next = new_node;
            
            pri = new_node;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            ListNode *new_node = new ListNode((l1->val + carry) % 10, NULL);
            carry = (l1->val + carry) >= 10 ? 1 : 0;
            
            pri->next = new_node;
            
            pri = new_node;
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            ListNode *new_node = new ListNode((l2->val + carry) % 10, NULL);
            carry = (l2->val + carry) >= 10 ? 1 : 0;
            
            pri->next = new_node;
            
            pri = new_node;
            l2 = l2->next;
        }
        
        if(carry)
        {
            ListNode *new_node = new ListNode(1, NULL);
            pri->next = new_node;
        }
        
        return ans_head;
    }
};
