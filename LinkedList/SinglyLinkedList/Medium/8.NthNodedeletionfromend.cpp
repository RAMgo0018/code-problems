/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]*/
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Count total number of nodes
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: If the head node needs to be removed
        if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Find position of node just before the target node
        int res = count - n;
        temp = head;

        for (int i = 1; i < res; i++) {
            temp = temp->next;
        }

        // Step 4: Delete the nth node from the end safely
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        // Step 5: Return updated head
        return head;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    int n = 2;  // Remove 2nd node from the end

    // Perform deletion
    head = obj.removeNthFromEnd(head, n);

    // Expected output: 1 2 3 5
    cout << "Linked List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
