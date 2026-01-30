/*Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
   
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:*/
#include <iostream>
using namespace std;

/* Node is defined as */
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* segregate(Node* head) {
        // dummy heads
        Node* zerohead = new Node(-1);
        Node* firsthead = new Node(-1);
        Node* secondhead = new Node(-1);

        Node* zero = zerohead;
        Node* first = firsthead;
        Node* second = secondhead;

        Node* temp = head;

        // divide nodes into 0s, 1s, and 2s lists
        while (temp != NULL) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                first->next = temp;
                first = first->next;
            }
            else if (temp->data == 2) {
                second->next = temp;
                second = second->next;
            }
            temp = temp->next;
        }

        // connect the lists
        zero->next = (firsthead->next) ? firsthead->next : secondhead->next;
        first->next = secondhead->next;
        second->next = NULL;

        // store answer
        Node* ans = zerohead->next;

        // delete dummy nodes
        delete zerohead;
        delete firsthead;
        delete secondhead;

        return ans;
    }
};

// helper to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // creating linked list: 1 -> 2 -> 0 -> 1 -> 2 -> 0
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.segregate(head);

    cout << "Segregated list: ";
    printList(head);

    return 0;
}
