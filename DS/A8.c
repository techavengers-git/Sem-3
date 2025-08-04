#include<stdio.h>
#define size 7

int Queue[size];
int front=-1, rear=-1, last=0;

int Enqueue(int n) {
    if((rear>=size-1 && front == -1) || (last==1 && rear+1==front)) {
        printf("Queue Overflow\n");
        return 1;
    }
    else {
        if(front == -1) {
            front = 0;
        }
        if(rear==size-1) {
            last=1;
            rear=-1;
        }
        Queue[++rear] = n;
    }
    return 0;
}

int Dequeue() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        int y=Queue[front];
        Queue[front++]=-1;
        return y;
    }
}

void Display() {
    if(front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int j = last ? 0 : front;
        int k = last ? size : rear+1;
        for(int i = j; i < k; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main() {

    while(1) {
        int n;
        printf("Enter value : ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        if(Enqueue(n)){
            return 0;
        }
    }

    int t;
    while(1) {
        int c;
        printf("\nEnter choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        scanf("%d", &c);

        if(c==-1) {
            break;
        }
        printf("\n");
        switch(c) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &t);
                if(Enqueue(t)) {
                    return 0;
                }
            break;
            case 2:
                t = Dequeue();
                if(t != -1) {
                    printf("Dequeued: %d\n", t);
                }
            break;
            case 3:
                Display();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("\n");
        Display();
        printf("\n");
    }

    return 0;
}