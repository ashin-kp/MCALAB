#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//insert into bst
struct Node *insert(struct Node *root,int data) {
    if(root == NULL)
        return createNode(data);
    
    if(data < root->data)
        root->left = insert(root->left,data);
    else if(data > root->data)
        root->right = insert(root->right,data);

    return root;
}

//find minimum value node 
struct Node *findMin(struct Node *root) {
    while(root->left != NULL) 
        root = root->left;
    return root;
}

//delete a node from bst

struct Node *deleteNode(struct Node *root,int key) {
    if(root == NULL) {
        return root;
    }

    if(key < root->data) 
        root->left = deleteNode(root->left,key);
    else if(key > root->data) 
        root->right = deleteNode(root->right,key);

    else {
        //case 1 no child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        //case 2 one child
        if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        //case 3 two children
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);

    }
    return root;
}

void inorder(struct Node *root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    int choice,value;
    while(1) {
        printf("\n1.insert 2.delete 3.inorder 4.preorder 5.postorder 6.exit : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            printf("enter value : ");
            scanf("%d",&value);
            root = insert(root,value);
            break;
            
            case 2:
            printf("enter value to delete : ");
            scanf("%d",&value);
            root = deleteNode(root,value);
            break;

            case 3:
            printf("inorder : ");
            inorder(root);
            printf("\n");
            break;

            case 4:
            printf("preorder : ");
            preorder(root);
            printf("\n");
            break;
            case 5:
            printf("postorder : ");
            postorder(root);
            printf("\n");
            break;
            default: printf("enter a valid number : ");
        }

    }
}