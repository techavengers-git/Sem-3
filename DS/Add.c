#include <stdio.h>
#include <stdlib.h>



struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=data;
    newNode->next=NULL;
    return newNode;
}

struct ListNode* insertNode(struct ListNode** head, int data) {
    struct ListNode* newNode= createNode(data);
    
    if(*head==NULL) {
        *head=newNode;
        return *head;
    }

    (*head)->next=newNode;
    *head=newNode;
    return *head;
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int ex=0;
    int in=0;
    struct ListNode* ans=NULL;
    struct ListNode* save=NULL;

    while(l1!=NULL || l2!=NULL) {
        int a = (l1!=NULL) ? l1->val : 0;
        int b = (l2!=NULL) ? l2->val : 0;
        
        in=a+b+ex;
        save=insertNode(&save, (in%10));
        ex=in/10;

        if (ans == NULL) {
            ans = save;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    while (ex > 0) {
        save = insertNode(&save, (ex % 10));
        ex /= 10;
    }

    return ans;   
}

int main() {
    
}