#include <stdio.h>

struct Queue{
    int front,rear;
    int arr[25];
};

int empty(struct Queue *a){
    if(a->front>a->rear)
        return 1;
    return 0;
}

void enqueue(struct Queue *a,int e){
    if(a->rear == (sizeof(a->arr)-1)){
        printf("Overflow!!!");
        return;
    }
    a->rear+=1;
    a->arr[a->rear] = e;
    return;
}

int dequeue(struct Queue *a){
    int e = a->arr[a->front];
    a->front++;
    return e;
}

void peek(struct Queue *a){
    if(empty(a)){
        printf("Empty Queue!!!\n");
        return;
    }
    printf("Element at the front of the Queue: %d\n",a->arr[a->front]);
    return;
}

int main(){
    int op,e,flag;
    struct Queue *q;
    q->front = 0;
    q->rear = -1;
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