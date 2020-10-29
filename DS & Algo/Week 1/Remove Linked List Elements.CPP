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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head, *pri = NULL;
	    while(curr != NULL)
	    {
            if(curr->val == val)
                curr == head ? head = curr->next : pri->next = curr->next;
		    else
                pri = curr;
            curr = curr->next;
	    }
        return head;
    }
};
