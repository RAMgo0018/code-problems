/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.*/
#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to detect cycle and return starting node of cycle
ListNode* detectCycle(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find starting point of cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL; // No cycle
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    //                          ^              |
    //                          |______________|

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating a cycle (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    ListNode* cycleStart = detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
