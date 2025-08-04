#include<stdio.h>
#define size 10

int Stack[size];
int top=-1;

void push(int n) {
    if(top>=size-1) {
        printf("Stack Overflow\n");
        return ;
    }
    Stack[++top]=n;
}

int pop() {
    if(top==-1) {
        printf("Stack Underflow\n");
        return ;
    }
    return Stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", Stack[i]);
        }
        printf("\n");
    }
}

int main() {

    int t;
    while(t--) {
        int n;
        printf("Enter size : ");
        scanf("%d", &n);
        int A[n],B[n];
        for(int i=0; i<n; i++) {
            int k;
            printf("Enter value : ");
            scanf("%d", &k);
            A[i]=k;
        }

    }
}