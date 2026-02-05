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

Node* deleteFromEnd(Node* head) {
    if(head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    // only one node
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;

    // go to last node
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // now temp is last node and prev is second last
    prev->next = NULL;
    delete temp;

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

    cout << "Before deletion: ";
    printList(head);

    head = deleteFromEnd(head);

    cout << "\nAfter deletion: ";
    printList(head);

    return 0;
}
