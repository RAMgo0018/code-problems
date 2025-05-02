/*class Solution{
    public:
    int findMiddle(Node * head)
    {
        Node * front=head;
        Node * back=head->prev;
        while(front!=back)
        {
            front=front->next;
            back=back->prev;
        }
        return front->data;
    }
};*/