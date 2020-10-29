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
    bool isPalindrome(ListNode* head) {
        ListNode *curr = head, *pri = NULL, *new_head = NULL;
        while(curr != NULL)
        {
            ListNode *temp = new ListNode(curr->val,pri);
            pri = temp;
            curr = curr->next;
        }
        new_head = pri;
        while(head != NULL)
        {
            if(new_head->val != head->val)
                return 0;
            new_head = new_head->next;
            head = head->next;
        }
        return 1;
    }
};
