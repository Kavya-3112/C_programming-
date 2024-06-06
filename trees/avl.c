#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX(A,B) (A)>(B)?(A):(B)

typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
    int height;
} Node;

typedef struct _avl
{
    Node* root;
    int len;
}AVL;

Node* createNode(int val)
{
    Node* nd=(Node*)malloc(sizeof(Node));
    nd->data=val;
    nd->left=nd->right=NULL;
    nd->height=1;
    return nd;
}
AVL* createAVL()
{
    AVL* b=(AVL*)malloc(sizeof(AVL));
    b->root=NULL;
    b->len=0;
    return b;
}
int height(Node* nd)
{
    if(nd==NULL)
        return 0;
    else
        return nd->height;
}
Node* rightRotate(Node* y) {//y b x a z c
    Node* x = y->left;
    Node* z = x->right;

    // Perform rotation
    x->right = y;
    y->left = z;

    // Update heights
    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z= y->left;

    // Perform rotation
    y->left = x;
    x->right = z;

    // Update heights
    x->height = MAX(height(x->left), height(x->right)) + 1;
    y->height = MAX(height(y->left), height(y->right)) + 1;

    return y;
}
Node* insertNode(Node* root,int data)
{

    if(root==NULL)
        return createNode(data);
    else if(data>root->data)
        root->right=insertNode(root->right,data);
    else if(data<root->data)
        root->left=insertNode(root->left,data);



    root->height=MAX(height(root->left),height(root->right))+1;
    

    
    int balancefactor=height(root->left)-height(root->right);
    if(balancefactor>1 && data<root->left->data)
    {
        //LL imbalance
        return rightRotate(root);//root=rightRotate(root)
    }
    else if(balancefactor>1 && data>root->left->data)
    {
        //LR imbalance
        root->left=leftRotate(root->left);
        return rightRotate(root);//root=rightRotate(root)
    }
    else if(balancefactor<-1 && data>root->right->data)
    {
        //RR imbalance
        return leftRotate(root);
    }
    else if(balancefactor<-1 && data<root->right->data)
    {
        //RL imbalance
        root->right=rightRotate(root->right);
        return leftRotate(root);//root=leftRotate(root)
    }
    return root;
}
Node* deleteNode(Node* root,int data)
{
    if(root==NULL)
        return root;
    else if(data>root->data)
        root->right=deleteNode(root->right,data);
        //return root;
    else if(data<root->data)
        root->left=deleteNode(root->left,data);
        //return root;
    else{
        if(root->left==NULL)
            return root->right;//return address of right
        else if(root->right==NULL)
            return root->left;
        else{
            Node* succParent=root;
            Node* succ=root->right;
            while(succ!=NULL && succ->left!=NULL)
            {
                succParent=succ;
                succ=succ->left;
            }
            root->data=succ->data;
            if(succParent!=root)
                succParent->left=succ->right;
            else
                succParent->right=succ->right;
        }
    }
    int balancefactor=height(root->left)-height(root->right);
    if(balancefactor>1 && data<root->left->data)
    {
        //LL imbalance
        return rightRotate(root);//root=rightRotate(root)
    }
    else if(balancefactor>1 && data>root->left->data)
    {
        //LR imbalance
        root->left=leftRotate(root->left);
        return rightRotate(root);//root=rightRotate(root)
    }
    else if(balancefactor<-1 && data>root->right->data)
    {
        //RR imbalance
        return leftRotate(root);
    }
    else if(balancefactor<-1 && data<root->right->data)
    {
        //RL imbalance
        root->right=rightRotate(root->right);
        return leftRotate(root);//root=leftRotate(root)
    }
    return root;
}
bool search(Node* root,int data)
{
    if(root==NULL)
        return false;
    else if(data>root->data)
        return search(root->right,data);
    else if(data<root->data)
        return search(root->left,data);
    else    
        return true;

}
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main() {
    // Create an AVL tree
    AVL* myAVL = createAVL();

    // Insert nodes into the AVL tree
    myAVL->root = insertNode(myAVL->root, 50);
    myAVL->root = insertNode(myAVL->root, 30);
    myAVL->root = insertNode(myAVL->root, 70);
    myAVL->root = insertNode(myAVL->root, 20);
    myAVL->root = insertNode(myAVL->root, 40);
    myAVL->root = insertNode(myAVL->root, 60);
    myAVL->root = insertNode(myAVL->root, 80);

    // Print the inorder traversal of the AVL tree
    printf("Inorder Traversal: ");
    inorder(myAVL->root);
    printf("\n");

    // Search for a value in the AVL tree
    int searchValue = 40;
    if (search(myAVL->root, searchValue)) {
        printf("%d is present in the AVL tree\n", searchValue);
    } else {
        printf("%d is not present in the AVL tree\n", searchValue);
    }

    // Delete a node from the AVL tree
    int deleteValue = 30;
    myAVL->root = deleteNode(myAVL->root, deleteValue);

    // Print the updated inorder traversal after deletion
    printf("Inorder Traversal after deleting %d: ", deleteValue);
    inorder(myAVL->root);
    printf("\n");

    return 0;
}
