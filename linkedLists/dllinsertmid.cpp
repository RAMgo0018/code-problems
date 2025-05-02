/*class Solution {
    public:
        Node* addNode(Node* head, int pos, int data) {
            Node* newnode = new Node(data);
            if (head == NULL) return newnode;
            Node* cur = head;
            for (int i = 0; i < pos && cur->next != NULL; i++) cur = cur->next;
            if (cur->next == NULL) {
                cur->next = newnode;
                newnode->prev = cur;
            } else {
                newnode->next = cur->next;
                cur->next->prev = newnode;
                cur->next = newnode;
                newnode->prev = cur;
            }
            return head;
        }
    };*/