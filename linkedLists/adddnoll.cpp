/*class Solution {
    public:
        Node* reverse(Node* head) {
            Node* prev = NULL, *current = head, *next;
            while (current) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }
    
        Node* addTwoLists(Node* num1, Node* num2) {
            num1 = reverse(num1);
            num2 = reverse(num2);
            Node* sum = NULL;
            int carry = 0;
    
            while (num1 || num2 || carry) {
                int newVal = carry;
                if (num1) newVal += num1->data, num1 = num1->next;
                if (num2) newVal += num2->data, num2 = num2->next;
                carry = newVal / 10;
                newVal %= 10;
                Node* newNode = new Node(newVal);
                newNode->next = sum;
                sum = newNode;
            }
    
            while (sum && sum->data == 0) {
                Node* temp = sum;
                sum = sum->next;
                delete temp;
            }
    
            return sum ? sum : new Node(0);
        }
    };*/