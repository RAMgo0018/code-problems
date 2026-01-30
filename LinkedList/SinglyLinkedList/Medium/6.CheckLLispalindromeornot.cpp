/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true*/
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

class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* Middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* mid = Middle(head);
        ListNode* rev = reverse(mid);

        ListNode* curr = head;
        while (rev != NULL)
        {
            if (rev->val != curr->val)
                return false;

            rev = rev->next;
            curr = curr->next;
        }
        return true;
    }
};

int main() {
    // Example 1: Palindrome list
    // 1 -> 2 -> 3 -> 2 -> 1

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "Linked List is Palindrome" << endl;
    else
        cout << "Linked List is NOT Palindrome" << endl;

    return 0;
}
