/*Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]*/
#include <bits/stdc++.h>
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

    ListNode* findtail(ListNode* temp) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }

    int length(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int len = length(head);
        k = k % len;
        if (k == 0) return head;

        ListNode* tail = findtail(head);
        tail->next = head;   // make circular

        int res = len - k;
        ListNode* temp = head;

        for (int i = 1; i < res; i++) {
            temp = temp->next;
        }

        ListNode* newhead = temp->next;
        temp->next = NULL;   // break circle

        return newhead;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;
    head = obj.rotateRight(head, k);

    // Print rotated list
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
