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

void delFirst(struct node** head) {
    struct node* temp = *head;
    *head = (*head)->link;
    free(temp);
}

struct node* partitionList(struct node** head, int k) {
    struct node* ans=createNode(-1);
    struct node* save=createNode(-1);
    save->link = *head;
    struct node* save1=save;

    while((save->link)!=NULL) {
        if((save->link)->info<k) {
            struct node* temp=save->link;
            save->link=(save->link)->link;
            ans->link=temp;
            if(ans->info==-1) {
                *head=ans->link;
            }
            ans=ans->link;
        }
        else {
            save=save->link;
        }
    }

    delFirst(&save1);
    ans->link=save1;
    
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

    list = partitionList(&list, k);

    displayList(&list);
    return 0;
}