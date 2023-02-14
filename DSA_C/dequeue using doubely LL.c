#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node * NP;

NP front1;
NP rear1;
NP front2;
NP rear2;

void enqueue1(int e){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;
    p->prev = NULL;
    if(rear1 == NULL){
        rear1 = p;
        front2 = p;
        rear2 = p;
        front1 = p;
        return;
    }
    rear1->prev = p;
    p->next = rear1;
    rear1 = p;
    front1 = rear1;
    return;
}

void enqueue2(int e){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;
    p->prev = NULL;
    if(rear2 == NULL){
        rear2 = p;
        front1 = p;
        rear1 = p;
        front2 = p;
        return;
    }
    rear2->next = p;
    p->prev = rear2;
    rear2 = p;
    front2 = rear2;
    return;
}

void dequeue1(){
    int x;
    if(front1 == NULL){
        printf("Underflow!!\n");
        return;
    }
    NP p = (NP)malloc(sizeof(struct node));
    p = front1;
    x = p->data;
    front1 = front1->next;
    rear1 = front1;
    free(p);
    printf("Element removed from front of the queue: %d\n",x);
    return;
}

void dequeue2(){
    int x;
    if(front2 == NULL){
        printf("Underflow!!\n");
        return;
    }
    NP p = (NP)malloc(sizeof(struct node));
    p = front2;
    x = p->data;
    front2 = front2->prev;
    rear2 = front2;
    free(p);
    printf("Element removed from the end of the queue: %d\n",x);
    return;
}

void peek1(){
    printf("Element at the front of the Queue:%d\n",front1->data);
    return;
}

void peek2(){
    printf("Element at the end of the Queue:%d\n",front2->data);
    return;
}

int main(){
    enqueue1(1);
    enqueue1(2);
    peek1();
    enqueue2(3);
    enqueue2(4);
    peek2();
    dequeue1();
    peek1();
    dequeue2();
    peek2();
    return 0;
} 