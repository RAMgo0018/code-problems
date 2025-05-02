/*class Solution {
    public:
        Node* deleteNode(Node* head, int x) {
            Node* del = head;
            x--;
            while (x--) del = del->next;
            if (!head || !del) return NULL;
            if (head == del) head = del->next;
            if (del->next) del->next->prev = del->prev;
            if (del->prev) del->prev->next = del->next;
            delete del;
            return head;
        }
    };*/