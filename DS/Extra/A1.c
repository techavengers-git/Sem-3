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


void insertFirst(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->link = *head;
    *head = newNode;
}


struct node* reverseList(struct node** head, int k) {
    struct node* save=*head;
    struct node* ans=NULL;
    struct node* ans1=NULL;

    while(save->link!=NULL) {
        struct node* temp=NULL;
        int count=0;

        while(count < k && save != NULL) {
            insertFirst(&temp, save->info);
            save = save->link;
            count++;
        }

        if (ans == NULL) {
            ans=temp;
        }
        ans1=temp;
        while(ans1->link!=NULL) {
            ans1=ans1->link;
        }
        ans->link = ans1;
        
        if(count ==k) {
            count = 0;
        }
    }

    return ans;
}

void displayList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->link;
    }
    printf("\n");
}


int main() {
    struct node* list=NULL;

    while(1) {
        int n;
        printf("Enter value : ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        insertNode(&list, n);
    }

    int k;
    printf("Enter k : ");
    scanf("%d", &k);

    list = reverseList(&list, k);

    displayList(list);
    return 0;
}