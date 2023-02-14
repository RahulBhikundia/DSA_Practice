#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node * NP;

NP front;
NP rear;

void enqueue(int e){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;
    if(rear == NULL){
        rear = p;
        front = p;
        return;
    }
    rear->next = p;
    rear = p;
    return;
}

void dequeue(){
    int x;
    if(front == NULL){
        printf("Underflow!!\n");
        return;
    }
    NP p = (NP)malloc(sizeof(struct node));
    p = front;
    x = p->data;
    front = front->next;
    free(p);
    printf("Removed element: %d\n",x);
    return;
}

void peek(){
    printf("Element at the front of the Queue:%d\n",front->data);
    return;
}

int main(){
    enqueue(1);
    enqueue(2);
    peek();
    enqueue(3);
    enqueue(4);
    peek();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}