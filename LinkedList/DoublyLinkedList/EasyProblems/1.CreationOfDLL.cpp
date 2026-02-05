#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    // Creating nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Linking nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    // Print forward
    cout << "Forward traversal: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Print backward
    cout << "\nBackward traversal: ";
    temp = third;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    return 0;
}
