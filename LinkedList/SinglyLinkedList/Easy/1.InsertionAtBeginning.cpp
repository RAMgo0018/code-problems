#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node(val);  // passing value directly
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printList(head);
    return 0;
}
