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

bool searchElement(Node* head, int key) {
    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            return true;   // found
        }
        temp = temp->next;
    }

    return false;  // not found
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

    int key = 30;

    if(searchElement(head, key)) {
        cout << "\nElement found";
    } else {
        cout << "\nElement not found";
    }

    return 0;
}
