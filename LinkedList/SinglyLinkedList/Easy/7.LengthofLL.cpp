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

int findLength(Node* head) {
    int count = 0;
    Node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
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

    printList(head);

    cout << "\nLength of linked list = " << findLength(head);

    return 0;
}
