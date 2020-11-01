/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> next_node;
        Node *temp = head;
        while(temp != NULL)
        {
            if(temp->child != NULL)
            {
                next_node.push(temp->next);
                temp->child->prev = temp;
                temp->next = temp->child;
                temp->child = NULL;
            }
            
            if(temp->next == NULL && !next_node.empty())
            {
                Node *old = next_node.top();
                if(old != NULL)
                    old->prev = temp; 
                temp->next = old;
                next_node.pop();
            }
            
            temp = temp->next;
        }
        return head;
    }
};
