
/*class Solution{
    public:
    bool isCircular(Node * head)
    {
        if(head->prev==NULL)
        return false;
        Node *temp=head->prev;
        if(temp->next==NULL)
        return false;
        if(temp->next==head &&head->prev==temp)
        return true;
        return false;  
    }
};*/