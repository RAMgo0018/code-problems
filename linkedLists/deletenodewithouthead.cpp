/*class Solution {
    public:
        void deleteNode(Node* del_node) {
            if (!del_node || !del_node->next) return;
            Node* temp = del_node->next;
            del_node->data = temp->data;
            del_node->next = temp->next;
            delete temp;
        }
    };*/