/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/
#include <iostream>
using namespace std;

// Definition of linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to detect cycle in linked list
bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    if (head->next == NULL) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

// Function to create a cycle (for testing)
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* temp = head;
    ListNode* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode;
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle at position 1 (node with value 2)
    createCycle(head, 1);

    if (hasCycle(head))
        cout << "Cycle detected in linked list" << endl;
    else
        cout << "No cycle in linked list" << endl;

    return 0;
}
