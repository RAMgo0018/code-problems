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

// Find length of DLL
int getLength(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Delete from beginning
Node* Deletebegin(Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete(head);
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete(temp);

    return head;
}

// Delete from end
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

// Delete kth node (using for loop to reach kth)
Node* Deletekth(Node* head, int k)
{
    if (head == NULL)
        return NULL;

    int len = getLength(head);

    if (k < 1 || k > len)
        return head;

    if (k == 1)
        return Deletebegin(head);

    if (k == len)
        return Deleteend(head);

    Node* temp = head;

    for (int i = 1; i < k; i++)
    {
        temp = temp->next;
    }

    Node* prev = temp->prev;
    Node* front = temp->next;

    prev->next = front;
    front->prev = prev;

    temp->next = NULL;
    temp->prev = NULL;
    delete(temp);

    return head;
}

// Print list
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
    // Create DLL: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    cout << "Before deletion: ";
    printList(head);

    int k = 2;
    head = Deletekth(head, k);

    cout << "After deleting " << k << "th node: ";
    printList(head);

    return 0;
}
