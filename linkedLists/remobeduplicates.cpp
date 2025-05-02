/*struct Node* removeDuplicates(struct Node* head) {
    if (!head) return NULL;
    struct Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}*/