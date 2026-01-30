/*You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. */
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
  
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addOne(Node* head) {
        head = reverse(head);
        Node* temp = head;
        int carry = 1;

        while (temp != NULL) {
            temp->data = temp->data + carry;
            if (temp->data < 10) {
                carry = 0;
                break;
            } else {
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }

        if (carry == 1) {
            Node* newnode = new Node(1);
            head = reverse(head);
            newnode->next = head;
            return newnode;
        }

        head = reverse(head);
        return head;
    }
};

int main() {
    // Creating linked list: 9 -> 9 -> 9
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    Solution obj;
    head = obj.addOne(head);

    // Print updated list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
