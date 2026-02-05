/*You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.*/
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

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

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

// Delete all occurrences of x
void deleteAllOccurOfX(Node** head_ref, int x) {
    Node *temp = *head_ref;
        
    while (temp != NULL) {
        if (temp->data == x) {
            // If deleting head node
            if (temp == *head_ref) {
                *head_ref = (*head_ref)->next;
            }

            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            if (nextNode) nextNode->prev = prevNode;
            if (prevNode) prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }
}

int main() {
    Node* head = NULL;

    // Create DLL: 10 <-> 20 <-> 10 <-> 30 <-> 10 <-> 40
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 40);

    cout << "Original list: ";
    printList(head);

    int x;
    cin >> x;   // value to delete

    deleteAllOccurOfX(&head, x);

    cout << "After deleting all occurrences of " << x << ": ";
    printList(head);

    return 0;
}
