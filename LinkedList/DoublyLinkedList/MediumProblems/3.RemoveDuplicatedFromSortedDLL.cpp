/*Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Example 1:

Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node *removeDuplicates(struct Node *head) {
        Node* temp = head;

        while(temp != NULL && temp->next != NULL)
        {
            Node* nextNode = temp->next;

            while(nextNode != NULL && nextNode->data == temp->data)
            {
                nextNode = nextNode->next;
            }

            temp->next = nextNode;
            if(nextNode)
                nextNode->prev = temp;

            temp = temp->next;
        }
        return head;
    }
};

// Function to insert at end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL)
        return newNode;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to print DLL
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;   // number of nodes

    Node* head = NULL;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtEnd(head, x);
    }

    Solution obj;
    head = obj.removeDuplicates(head);

    printList(head);

    return 0;
}
