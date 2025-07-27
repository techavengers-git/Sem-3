#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node* lptr;
    struct node* rptr;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

struct node* insertNode(struct node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return *root;
    }
    if (value < (*root)->info) {
        (*root)->lptr = insertNode(&((*root)->lptr), value);
    } else if (value > (*root)->info) {
        (*root)->rptr = insertNode(&((*root)->rptr), value);
    }
    return *root;
}


void deleteNode(struct node** root, int value) {

}



void searchNode(struct node** root, int value) {
    if (*root == NULL || (*root)->info == value) {
        printf("Node with value %d found.\n", value);
        return;
    }
    if (value < (*root)->info) {
        return searchNode(&((*root)->lptr), value);
    }
    else if (value > (*root)->info) {
        searchNode(&((*root)->rptr), value);
    }
    printf("Node with value %d not found.\n", value);
    return;
}


void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->info);
    preorder(root->lptr);
    preorder(root->rptr);
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lptr);
    printf("%d ", root->info);
    inorder(root->rptr);
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d ", root->info);
}

int main() {

    struct node* bst = NULL;

    int n;
    while(1) {
        printf("Enter value : ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        else {
            insertNode(&bst, n);
        }
    }

    int t;
    while(1) {
        int c;
        printf("Chose option from below:\n");
        printf("1. insert node\n");
        printf("2. delete node\n");
        printf("3. search node\n");
        printf("4. preorder traversal\n");
        printf("5. inorder traversal\n");
        printf("6. postorder traversal\n");
        printf("-1. exit\n");
        scanf("%d", &c);


        switch(c) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &t);
                insertNode(&bst, t);
            break;
            case 2:
                printf("Delete operation not implemented yet.\n");
            break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &t);
                searchNode(&bst, t);
            break;
            case 4:
                printf("\nPreorder traversal: ");
                preorder(bst);
                printf("\n");
            break;
            case 5:
                printf("\nInorder traversal: ");
                inorder(bst);
                printf("\n");
            break;
            case 6:
                printf("\nPostorder traversal: ");
                postorder(bst);
                printf("\n");
            break;
        }
        if(c == -1) {
            break;
        }
        

    }
}