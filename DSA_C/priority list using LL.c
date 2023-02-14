#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int pr;
    struct node *next;
};

typedef struct node * NP;

NP head;

void push(int ele, int prio){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = ele;
    p->pr = prio;
    p->next = NULL;
    if(head == NULL){
        head = p;
        return;
    }
    if(head->pr < prio){
        p->next = head;
        head = p;
        return;
    }
    NP temp = head;
    while(temp->next != NULL && temp->next->pr > prio)
        temp = temp->next;
    p->next = temp->next;
    temp->next = p;
    return;
}

void pop(){
    if(head == NULL){
        printf("Underflow!!\n");
    }
    NP temp = head;
    int e = temp->data;
    head = head->next;
    free(temp);
    printf("Removing element with the highest priority:%d\n",e);
    return;
}

void peek(){
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    printf("Element with the highest priority:%d\n",head->data);
    return;
}

int main(){
    push(2,3);
    push(1,5);
    push(4,2);
    push(5,6);
    peek();
    pop();
    pop();
    pop();
    pop();
    return 0;
}