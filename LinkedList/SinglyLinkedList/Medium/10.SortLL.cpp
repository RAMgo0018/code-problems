/*Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]*/
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* DNode = new ListNode(0);   // dummy node
        ListNode* temp = DNode;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1) temp->next = list1;
        else temp->next = list2;

        ListNode* result = DNode->next;
        delete DNode;        // free dummy node
        return result;
    }

    // Find node before the middle
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge sort on linked list
    ListNode* sortList(ListNode* head) {
        // Base case
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* lefthead = head;
        ListNode* middle = middleNode(head);
        ListNode* righthead = middle->next;

        middle->next = NULL;   // split the list

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return mergeTwoLists(lefthead, righthead);
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
    // Create linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution obj;

    cout << "Original List: ";
    printList(head);

    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
