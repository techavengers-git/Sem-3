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


struct node* rotateList(struct node** head, int k, int len) {
    if(k>len) {
        k = k % len;
    }
    
    int count=len-k;

    struct node* save=*head;
    struct node* ans=NULL;

    count--;
    while(count--) {
        save=save->link;
    }
    ans=save->link;
    while(ans->link!=NULL) {
        ans=ans->link;
    }
    ans->link = *head;
    *head = save->link;
    save->link = NULL;

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

    list = rotateList(&list, k, len);

    displayList(&list);
    return 0;
}