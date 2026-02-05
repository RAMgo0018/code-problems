#include <iostream>
using namespace std;

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

// Function to create DLL from array
Node* createDLL(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

// Print forward
void printForward(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createDLL(arr, n);

    cout << "Doubly Linked List: ";
    printForward(head);

    return 0;
}
