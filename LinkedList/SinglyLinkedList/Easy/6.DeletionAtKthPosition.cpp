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

Node* deleteAtK(Node* head, int k) {
    if(head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    // case: delete first node
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    // move to kth node
    for(int i = 1; i < k && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // if k is out of range
    if(temp == NULL) {
        cout << "Position out of range\n";
        return head;
    }

    prev->next = temp->next;  // unlink
    delete temp;              // delete kth node

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

    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Before deletion: ";
    printList(head);

    head = deleteAtK(head, 3);   // delete 3rd node (30)

    cout << "\nAfter deletion: ";
    printList(head);

    return 0;
}
