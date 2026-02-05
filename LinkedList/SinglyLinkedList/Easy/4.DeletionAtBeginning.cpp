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

Node* deleteFromBeginning(Node* head) {
    if(head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;
    head = head->next;   // move head
    delete temp;         // delete old head

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

    cout << "Before deletion: ";
    printList(head);

    head = deleteFromBeginning(head);

    cout << "\nAfter deletion: ";
    printList(head);

    return 0;
}
