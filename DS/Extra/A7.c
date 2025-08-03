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

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* reorderList(struct node** head, int len) {
    struct node* save=*head;
    struct node* ans=*head;
    struct node* save1=ans;

    if(len<3) {
        return *head;
    }

    save=save->link;

    while(save!=NULL) {
        save=reverseList(save);
        ans->link=save;
        ans=ans->link;
        save=save->link;
    }

    return save1;
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

    list = reorderList(&list, len);

    displayList(&list);
    return 0;
}