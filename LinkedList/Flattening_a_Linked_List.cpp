/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
   
// Merge two bottom linked lists
Node *merge(Node* a,Node* b){
    Node* temp = new Node(0);
    Node* t = temp;
    
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->bottom = a;
            temp=temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    
    if(a) temp->bottom=a;
    else temp->bottom=b;
    
    return t->bottom;
} 
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL) return root;
   
   // Right side list
   root->next = flatten(root->next);
   
   // Merging the buttom list || Row wise merging
   root = merge(root,root->next);
   
   return root;
 
}
