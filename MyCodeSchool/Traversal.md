![Capture](https://user-images.githubusercontent.com/63875409/124087617-cb2ed080-da6f-11eb-944a-2f28fd25d307.PNG)




# Level Order Traversal (BFS)

```

#include <iostream>
#include <queue>

using namespace std;

class BstNode{
  public:
   BstNode* left;  // Left Child Reference
   int data;     // Data
   BstNode* right;  // // Right Child Reference
   
   BstNode(int val){
       left = NULL;
       data = val;
       right = NULL;
   }
};

BstNode* Insert(BstNode* &root, int data){
    
    if(root == NULL){
        BstNode* newNode = new BstNode(data);
        root = newNode;
    }
    
    // 2 more cases
    
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    
    return root;
}

// TC : O(N) in all cases , SC : O(1) - Best Case O(N) - Worst case 

void LevelOrder(BstNode *root){
    if(root==NULL){
        return;
    }
    
    queue<BstNode*> q;
    
    q.push(root);
    
    while(!q.empty()){
        
        BstNode* curr = q.front();
        q.pop();
        cout<<curr->data;
        
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    
    return;
    
}


int main()
{
    BstNode* root = NULL;
    
    Insert(root,15);
    Insert(root,10);
    Insert(root,20);
    Insert(root,25);
    Insert(root,17);
    Insert(root,12);
    Insert(root,30);
    

    
    return 0;
}
 
```

# Preorder , Postorder , Inorder

```

# Node Class : Left | data | Right
class BstNode:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.data = key


def Inorder(root):
    
    if root:
        Inorder(root.left)
        print(root.data,end=" ")
        Inorder(root.right)


def Preorder(root):
    
    if root:
        print(root.data,end=" ")
        Preorder(root.left)
        Preorder(root.right)



def Postorder(root):
    
    if root:
        Postorder(root.left)
        Postorder(root.right)
        print(root.data,end=" ")



def Insert(root:BstNode,key:int):

    if root is None:
        return BstNode(key)

    else:
        if root.data == key:
            return root

        elif root.data < key:
            root.right = Insert(root.right, key)

        else:
            root.left = Insert(root.left,key)

    return root 


root = BstNode(15)
r = Insert(root, 10)
r = Insert(root, 20)
r = Insert(root, 8)
r = Insert(root, 14)
r = Insert(root, 17)
r = Insert(root, 25)

Inorder(root)
print()
Postorder(root)
print()
Preorder(root)
    
```
