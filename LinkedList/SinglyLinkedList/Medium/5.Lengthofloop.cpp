/*Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.

Examples:

Input: pos = 2,
   
Output: 4
Explanation: There exists a loop in the linked list and the length of the loop is 4.*/
#include <iostream>
using namespace std;

// Definition of Node
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
  
    int findlength(Node* slow, Node* fast)
    {
        int count = 1;
        fast = fast->next;
        
        while (slow != fast)
        {
            count++;
            fast = fast->next;
        }
        return count;
    }

    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
            {
                return findlength(slow, fast);
            }
        }
        return 0; // No loop
    }
};

int main() {
    // Create linked list
    // 1 -> 2 -> 3 -> 4 -> 5
    //           ^         |
    //           |_________|

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    int loopLength = obj.lengthOfLoop(head);

    if (loopLength > 0)
        cout << "Length of loop is: " << loopLength << endl;
    else
        cout << "No loop detected" << endl;

    return 0;
}
