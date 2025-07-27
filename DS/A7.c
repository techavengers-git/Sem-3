#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* lptr;
    struct node* rptr;
    int l;
    int r;
};


struct node* createNode(int data) {
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=data;
    newNode->lptr=NULL;
    newNode->rptr=NULL;
    newNode->l=0;
    newNode->r=0;
    return newNode;
}


int findHeight(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->lptr);
    int rightHeight = findHeight(root->rptr);
    return (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
}

struct node* leftRotation(struct node** root) {
    struct node* newRoot = (*root)->rptr;
    (*root)->rptr = newRoot->lptr;
    newRoot->lptr = *root;
    (*root)->r = findHeight((*root)->rptr);
    (*root)->l = findHeight((*root)->lptr);
    newRoot->l = findHeight(newRoot->lptr);
    newRoot->r = findHeight(newRoot->rptr);
    return newRoot;
}

struct node* rightRotation(struct node** root) {
    struct node* newRoot = (*root)->lptr;
    (*root)->lptr = newRoot->rptr;
    newRoot->rptr = *root;
    (*root)->r = findHeight((*root)->rptr);
    (*root)->l = findHeight((*root)->lptr);
    newRoot->l = findHeight(newRoot->lptr);
    newRoot->r = findHeight(newRoot->rptr);
    return newRoot;
}

struct node* insertNode(struct node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return *root;
    }
    if (data < (*root)->info) {
        (*root)->lptr = insertNode(&((*root)->lptr), data);
        (*root)->l = findHeight((*root)->lptr);
        (*root)->r = findHeight((*root)->rptr);
    }
    else if (data > (*root)->info) {
        (*root)->rptr = insertNode(&((*root)->rptr), data);
        (*root)->r = findHeight((*root)->rptr);
        (*root)->l = findHeight((*root)->lptr);
    }

    if((*root)->l - (*root)->r>1 || (*root)->r - (*root)->l>1) {
        if((*root)->l>(*root)->r) {
            if((*root)->lptr->l>(*root)->lptr->r) {
                return rightRotation(root);
            }
            else {
                (*root)->lptr=leftRotation(&(*root)->lptr);
                return rightRotation(root);
            }
        }
        else {
            if((*root)->rptr->r>(*root)->rptr->l) {
                return leftRotation(root);
            }
            else {
                (*root)->rptr=rightRotation(&(*root)->rptr);
                return leftRotation(root);
            }
        }
    }

    return *root;
}



void preorder(struct node* root) {
    if (root == NULL) {
        printf("-1, ");
        return;
    }
    printf("%d, ", root->info);
    preorder(root->lptr);
    preorder(root->rptr);
}


int main() {
    struct node* avl=NULL;

    while(1) {
        int n;
        printf("Enter data : ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        } else {
            avl = insertNode(&avl, n);
        }
    }

    printf("\n");
    printf("AVL Tree Preorder Traversal: \n");
    preorder(avl);
    printf("\b\b \n");

    // free(avl);
    return 0;
}