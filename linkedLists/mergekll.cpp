/*class Compare {
    public:
        bool operator()(Node* a, Node* b) { return a->data > b->data; }
    };
    
    class Solution {
    public:
        Node* mergeKLists(vector<Node*>& arr) {
            priority_queue<Node*, vector<Node*>, Compare> pq;
            for (Node* head : arr) if (head) pq.push(head);
            Node* dummy = new Node(-1), *tail = dummy;
            while (!pq.empty()) {
                Node* top = pq.top(); pq.pop();
                tail->next = top;
                tail = top;
                if (top->next) pq.push(top->next);
            }
            return dummy->next;
        }
    };*/