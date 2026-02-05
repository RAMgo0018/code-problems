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

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) {
        return newNode;   // first node
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
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

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printList(head);
    return 0;
}
