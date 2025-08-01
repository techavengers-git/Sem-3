#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* link;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->link = NULL;
    return newNode;
}

void insertNode(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* save = *head;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;
}


struct node* middleNode(struct node** head, int len) {
    len/=2;

    struct node* save=*head;

    while(len--) {
        save=save->link;
    }

    return save;
}



void displayList(struct node** head) {
    struct node* save = *head;
    while (save != NULL) {
        printf("%d ", save->info);
        save = save->link;
    }
    printf("\n");
}


int main() {
    struct node* list=NULL;
    int len=0;

    while(1) {
        int n;
        printf("Enter value : ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        len++;
        insertNode(&list, n);
    }

    list = middleNode(&list, len);

    displayList(&list);
    return 0;
}