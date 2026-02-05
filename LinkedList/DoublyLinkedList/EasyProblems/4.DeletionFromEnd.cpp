#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct Node 
{
    int data;
    Node* prev;
    Node* next;

    Node(int val) 
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* Deleteend(Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete(head);
        return NULL;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node* prev = temp->prev;
    prev->next = NULL;
    temp->prev = NULL;
    delete(temp);

    return head;
}

// Helper function to print list
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating doubly linked list: 10 <-> 20 <-> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Before deletion: ";
    printList(head);

    head = Deleteend(head);

    cout << "After deletion: ";
    printList(head);

    return 0;
}
