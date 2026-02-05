/*You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

Examples:

Input:
   
Output: 5 <-> 4 <-> 3
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.*/
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

// Insert at end (helper)
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

// Reverse Doubly Linked List
Node* reverseDLL(Node* head) {
    if(head == NULL)
        return head;
    if(head->next == NULL)
        return head;

    Node* curr = head;
    Node* last = NULL;

    while(curr != NULL) {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }

    return last->prev; // new head
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

    head = reverseDLL(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
