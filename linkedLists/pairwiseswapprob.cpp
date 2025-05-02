/*struct Node* pairwise_swap(struct Node* head) {
    if (!head || !head->next) return NULL;
    struct Node *prev = head, *curr = head->next;
    head = curr;
    while (true) {
        struct Node *next = curr->next;
        curr->next = prev;
        if (!next || !next->next) {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    return head;
}*/