/*class Solution {
    public:
        int getKthFromLast(Node *head, int k) {
            Node *currNode = head, *kthNode = head;
            while (k--) {
                if (!currNode) return -1;
                currNode = currNode->next;
            }
            while (currNode) {
                kthNode = kthNode->next;
                currNode = currNode->next;
            }
            return kthNode ? kthNode->data : -1;
        }
    };*/