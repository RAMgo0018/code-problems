/*class Solution {
    public:
        Node* swapKthNode(Node* head, int k) {
            Node* dummy = head;int num = 0;
            while (dummy) {dummy = dummy->next;num++;}
            if (k > num || 2 * k - 1 == num) return head;
    
            Node* x_prev = NULL, *x = head, *y_prev = NULL, *y = head;
            int count = k - 1;
            while (count--) {x_prev = x; x = x->next;}
    
            count = num - k;
            while (count--) {y_prev = y; y = y->next;}
    
            if (x_prev) x_prev->next = y;
            if (y_prev) y_prev->next = x;
    
            Node* temp = x->next;
            x->next = y->next;
            y->next = temp;
    
            if (k == 1) return y;
            if (k == num) return x;
            return head;
        }
    };
    */ 
    
    
    
    
    
    
    
    
    