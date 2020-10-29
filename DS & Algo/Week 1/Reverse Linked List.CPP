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
    ListNode* reverse(ListNode *node, ListNode **head)
    {
        if(node->next == NULL)
        {
            *head = node;
            return node;
        }
        ListNode *new_list = reverse(node->next, head);
        new_list->next = node;
        node->next = NULL;
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *new_list_head = NULL;
        if(head != NULL)
            reverse(head, &new_list_head);
        return new_list_head;
    }
};
