int isSorted(struct Node *head) {
    if (!head || !head->next) return 1;
    int increasing = 1, decreasing = 1;
    struct Node *temp = head, *temp2 = head->next;
    while (temp2) {
        if (temp2->data < temp->data) increasing = 0;
        temp2 = temp2->next;
        temp = temp->next;
    }
    temp = head, temp2 = head->next;
    while (temp2) {
        if (temp2->data > temp->data) decreasing = 0;
        temp2 = temp2->next;
        temp = temp->next;
    }
    return increasing || decreasing;
}