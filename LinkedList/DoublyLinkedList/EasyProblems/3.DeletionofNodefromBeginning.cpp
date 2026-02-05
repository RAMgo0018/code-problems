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

// Insert at end (helper function)
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL)
        return newNode;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete from beginning
Node* deleteFromBeginning(Node* head) {

    // Case 1: Empty list
    if (head == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return NULL;
    }

    // Case 2: Only one node
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Case 3: More than one node
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;

    return head;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Create DLL: 10 <-> 20 <-> 30 <-> 40
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    cout << "Original list: ";
    printList(head);

    head = deleteFromBeginning(head);

    cout << "After deleting from beginning: ";
    printList(head);

    return 0;
}
