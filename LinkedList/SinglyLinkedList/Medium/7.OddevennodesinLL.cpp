/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]*/
#include <iostream>
using namespace std;

// Definition of singly linked list node
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
    ListNode* oddEvenList(ListNode* head) {

        // Step 1: Edge cases
        // If list is empty or has only one node, return as it is
        if (head == NULL || head->next == NULL)
            return head;

        // Step 2: Initialize pointers
        // odd points to first node (odd position)
        // even points to second node (even position)
        ListNode* odd = head;
        ListNode* even = head->next;

        // Store head of even list to attach later
        ListNode* evenHead = even;

        // Step 3: Rearranging nodes
        // Continue until there are no more even nodes
        while (even != NULL && even->next != NULL) {

            // Link current odd node to next odd node
            odd->next = odd->next->next;

            // Link current even node to next even node
            even->next = even->next->next;

            // Move odd pointer forward
            odd = odd->next;

            // Move even pointer forward
            even = even->next;
        }

        // Step 4: Attach even list after odd list
        odd->next = evenHead;

        // Step 5: Return modified head
        return head;
    }
};

// Function to print linked list
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

    // Applying odd-even arrangement
    head = obj.oddEvenList(head);

    // Printing result
    // Expected output: 1 -> 3 -> 5 -> 2 -> 4
    cout << "Odd-Even Linked List: ";
    printList(head);

    return 0;
}
