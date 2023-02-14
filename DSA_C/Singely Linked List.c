#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node * NP;

NP head;

void insFront(int e){
    NP p = (NP)malloc(sizeof(struct node));
    p->data = e;
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
        head = p;
        return;
    }
    NP temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = p;
    return;
}

void delLast(){
    NP p = (NP)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Overflow!!\n");
        return;
    }
    NP temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    p = temp->next;
    printf("Data of node removed from last:%d\n",p->data);
    temp->next=NULL;
    free(p);
    return;
}

void delFront(){
    NP p = (NP)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Overflow!!\n");
        return;
    }
    p = head;
    printf("Data of node removed from front:%d\n",p->data);
    head = head->next;
    free(p);
    return;
}

void delAfter(int e){
    NP p = (NP)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Overflow!!\n");
        return;
    }
    NP temp = head;
    while(temp && temp->data != e){
        temp = temp->next;
    }
    if(temp && temp->next == NULL){
        printf("Not Possible\n");
        return;
    }
    p = temp->next;
    printf("Data of removed node:%d\n",p->data);
    temp->next = temp->next->next;
    free(p);
    return;
}

void delFirst(int e){
    NP p = (NP)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Overflow!!\n");
        return;
    }
    NP temp = head;
    while(temp->next && temp->next->data != e){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("Not Found\n");
        return;
    }
    p = temp->next;
    printf("Removed element:%d\n",p->data);
    temp->next = temp->next->next;
    free(p);
    return;
    
}

void delAll(int e){
    NP p = (NP)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Overflow!!\n");
        return;
    }
    NP temp = head;
    int count = 0;
    while(temp){
        if(temp->next->data == e){
            count++;
            p = temp->next;
            temp->next = temp->next->next;
            free(p);
        }
        temp = temp->next;
    }   
    if(count == 0){
        printf("Not found\n");
        return;
    }
    printf("%d occurences of %d deleted\n",count,e);
    return;
    
}

void freq(int e){
    NP temp = head;
    int count = 0;
    while(temp){
        if(temp->data == e)
            count++;
        temp = temp->next;
    }
    printf("Frequency of %d: %d\n",e,count);
    return;
}

int main(){
    insFront(1);
    insFront(2);
    insFront(3);
    insLast(4);
    insLast(1);
    freq(1);
    delAll(1);
    freq(1);
    delFront();
    delAfter(4);
    delFront();
    return 0;
}