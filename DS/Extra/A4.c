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

struct node* swapNode(struct node** head, int k, int len) {
    if(k==1) {
        struct node* temp=*head;

        while((temp->link)->link!=NULL) {
            temp = temp->link;
        }
        struct node* temp2 = temp->link;
        temp->link = NULL;
        (*head)->link=reverseList((*head)->link);
        temp=*head;
        while(temp->link!=NULL) {
            temp = temp->link;
        }
        temp->link = temp2;

        return reverseList(*head);
    }

    if(k>=len/2+1) {
        k = len - k + 1;
    }

    struct node* save=*head;
    struct node* save1=*head;
    for(int i=1; i<k-1; i++) {
        save = save->link;
    }
    for(int i=1; i<len-k; i++) {
        save1 = save1->link;
    }

    struct node* temp = save->link;
    struct node* temp1 = save1->link;
    struct node* temp2 = temp1->link;

    if(k==(len*1.0)/2) {
        temp1->link=save->link;
    }
    else {
        temp1->link=(save->link)->link;
        save1->link = temp;
    }

    save->link = temp1;
    temp->link = temp2;

    return *head;
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

    int k;
    printf("Enter k : ");
    scanf("%d", &k);

    list = swapNode(&list, k, len);

    displayList(&list);
    return 0;
}