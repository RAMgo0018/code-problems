/*Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert at end (helper to build list)
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Find rightmost node
Node* findright(Node* head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// Find pairs with given sum
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    vector<pair<int,int>> arr;
    if(head == NULL) return arr;
        
    Node *left = head;
    Node *right = findright(head);
        
    while (left != right && left->prev != right) {
        int sum = left->data + right->data;
            
        if (sum == target) {
            arr.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }
    return arr;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Create sorted DLL: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 9);

    cout << "Doubly Linked List: ";
    printList(head);

    int target;
    cin >> target;   // target sum

    vector<pair<int,int>> result = findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << ":\n";
    for(auto p : result) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
