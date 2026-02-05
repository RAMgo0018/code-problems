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

Node* insertAtK(Node* head, int val, int k) {
    Node* newNode = new Node(val);

    // case: insert at beginning
    if(k == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    // move to (k-1)th node
    for(int i = 1; i < k-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // if k is out of range
    if(temp == NULL) {
        cout << "Position out of range\n";
        return head;
    }

    newNode->next = temp->next;
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

    head = insertAtK(head, 10, 1); // 10
    head = insertAtK(head, 20, 2); // 10 20
    head = insertAtK(head, 30, 3); // 10 20 30
    head = insertAtK(head, 25, 3); // 10 20 25 30

    printList(head);
    return 0;
}
