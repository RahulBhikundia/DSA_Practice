#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NP;

NP head;

void insFront(int e){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = e;
    p->prev = NULL;
    if(head == NULL){
        p->next = NULL;
        head = p;
        return;
    }
    p->next = head;
    head = p;
    return;
}

void insLast(int e){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;
    if(head == NULL){
        p->prev = NULL;
        head = p;
        return;
    }
    NP temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    return;
} 

void delFront(){
    NP p;
    if(head == NULL){
        printf("Overflowing!!\n");
        return;
    }
    p = head;
    printf("Element romoved from front:%d\n",p->data);
    head = head->next;
    head->prev = NULL;
    free(p);
    return;
}

void delLast(){
    NP p;
    if(head == NULL){
        printf("Overflowing!!\n");
        return;
    }
    NP temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    p = temp->next;
    printf("Element removed from last:%d\n",p->data);
    temp->next = NULL;
    free(p);
    return;
}

void printDLL(){
    printf("Printing Elements of Doubley Linked List:\n");
    NP temp = head;
    while(temp){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    return;
}

int main(){
    insFront(1);
    insFront(2);
    insFront(3);
    insLast(4);
    printDLL();
    delFront();
    delLast();
    delFront();
    printDLL();
    delFront();
    return 0;
}