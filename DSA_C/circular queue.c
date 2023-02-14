#include <stdio.h>

struct Queue{
    int front,rear;
    int arr[25];
};

int empty(struct Queue *a){
    return ((a->rear == a->front)?1:0);
}

void enqueue(struct Queue *a,int e){
    int MAX = sizeof(a->arr);
    int temp = a->rear;
    if(a->rear == MAX-1)
        a->rear = 0;
    else
        a->rear++;
    if(a->rear==a->front){
        printf("OVERFLOW!!\n");
        a->rear = temp;
        return;
    }
    a->arr[a->rear] = e;
    return;
}

int dequeue(struct Queue *a){
    int MAX = sizeof(a->arr);
    if(a->front == MAX-1){
        a->front = 0;
    }
    else{
        a->front++;
    }
    return a->arr[a->front];
}

void peek(struct Queue *a){
    int i,MAX;
    MAX = sizeof(a->arr);
    if(empty(a)){
        printf("Empty Queue!!!\n");
        return;
    }
    if(a->front==MAX-1)
        i=0;
    else
        i=(a->front)+1;
    printf("Element at the front of the Queue: %d\n",a->arr[i]);
    return;
}

int main(){
    printf("Program for Circular Array\n");
    int op,e,flag;
    struct Queue *q;
    int MAX = sizeof(q->arr);
    q->front = MAX-1;
    q->rear = MAX-1;
    flag = 1;
    printf("Choose from following options(1,2,3,4):\n");
    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
    while(flag){
        printf("Choose Operation:");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Enter element:");
                scanf("%d",&e);
                enqueue(q,e);
                break;
            case 2:
                if(empty(q)){
                    printf("UNDERFLOW!!\n");
                    break;
                }
                e = dequeue(q);
                printf("Removed element: %d\n",e);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Please Choose a Correct option!!\n");
                break;
        }
    }
    printf("____________________Thank You_________________________");
}