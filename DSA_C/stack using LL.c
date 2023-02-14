#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node * NP;

NP head;

void push(int e){
    NP p = (NP)malloc(sizeof(struct node));
    if(head == NULL){
        p->data = e;
        p->next = NULL;
        head = p;
        return;
    }
    p->data = e;
    p->next = head;
    head = p;
    return;
}

void pop(){
    int x;
    if(head == NULL){
        printf("Underflow!!\n");
        return;
    }
    NP p = (NP)malloc(sizeof(struct node));
    p = head;
    x = p->data;
    head = head->next;
    free(p);
    printf("Removed element: %d\n",x);
    return;
}

void peek(){
    printf("Element at the top of the stack:%d\n",head->data);
    return;
}

int main(){
    push(1);
    push(2);
    peek();
    push(3);
    peek();
    push(4);
    peek();
    pop();
    pop();
}