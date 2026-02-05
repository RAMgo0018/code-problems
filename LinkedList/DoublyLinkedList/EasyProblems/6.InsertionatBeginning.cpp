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

// Insert at beginning
Node* insertAtBegin(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode; // new node becomes new head
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

    // Insert at beginning
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 40);

    cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}
