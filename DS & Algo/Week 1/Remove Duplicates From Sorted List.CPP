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
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *curr = head, *pri = NULL;
        while(curr != NULL)
        {
            pri = curr;
            curr = curr->next;
            while(curr != NULL && curr->val == pri->val)
                curr = curr->next;
            pri->next = curr;
        }
        return head;
    }
};
