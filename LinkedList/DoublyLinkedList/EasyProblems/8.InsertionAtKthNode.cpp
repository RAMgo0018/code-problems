#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert at end (helper to build list)
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Insert at given position
Node* insertAtPosition(Node* head, int pos, int val) {
    Node* newNode = new Node(val);

    // Insert at beginning
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;   // new head
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) return head;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Create list: 10 <-> 20 <-> 30 <-> 40
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    cout << "Original list: ";
    printList(head);

    int pos = 3, val = 25;
    head = insertAtPosition(head, pos, val);

    cout << "After inserting at position " << pos << ": ";
    printList(head);

    return 0;
}
