/*class Solution {
 public:
 int countNodesinLoop(Node* head) class Solution {
public:
int countNodesinLoop(Node* head) {  
Node* fast = head->next;
 Node* slow = head;
while (fast != slow) {        
if (fast == NULL || fast->next == NULL)
return 0;
      
fast = fast->next->next;
slow = slow->next;
int size = 1;
fast = fast->next;
      
             
while (fast != slow) {
fast = fast->next;                  
size++;}
              
return size;
}
};  
 Node* fast = head->next;
 Node* slow = head;
 while (fast != slow) {
             
if (fast == NULL || fast->next == NULL)
 return 0;
  
 fast = fast->next->next;
slow = slow->next;
 }
 int size = 1;
fast = fast->next;
while (fast != slow) {
 fast = fast->next;
size++;
 }
 return size;
}
};*/