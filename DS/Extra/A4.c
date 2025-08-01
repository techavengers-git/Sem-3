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


struct node* swapNode(struct node** head, int k, int len) {
    if(k==1) {
        struct node* temp=*head;

        while((temp->link)->link!=NULL) {
            temp = temp->link;
        }
        struct node* temp1 = *head;
        *head = temp->link;
        temp->link = temp1->link;
        temp->link=temp1;
        temp1->link = NULL;
        return *head;
    }

    int l=len-k-1;
    k-=2;

    struct node* save=*head;
    struct node* save1=*head;
    while(l--) {

        while(k-- && k>0) {
            save = save->link;
        }

        save1=save1->link;
    }

    struct node* temp = save->link;
    struct node* temp1 = save1->link;
    struct node* temp2 = temp1->link;

    temp1->link=(save->link)->link;


    save1->link = temp;
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