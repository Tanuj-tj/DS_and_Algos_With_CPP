class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        // Prev = NULL , current = Head , next = head->next
        struct Node* p = head;
        struct Node* q = NULL;
        struct Node* r = NULL;
    
        while(p!=NULL){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        } 
        head = q;
        return head;
    }
    
};