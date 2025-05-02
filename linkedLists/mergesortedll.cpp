/*struct Node* sortedMerge(struct Node* head1, struct Node* head2) {
    struct Node* dummy = newNode(0), *tail = dummy;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    return dummy->next;
}*/