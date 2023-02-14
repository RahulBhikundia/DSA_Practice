#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NP;

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

void reverse(void)
{
    NP prev = NULL;
    NP cur = head;
    NP nex = head->next;
    while(nex)
    {
        cur->next = prev;
        prev = cur;
        cur = nex;
        nex = nex->next;
    }
    cur->next = prev;
    head = cur;

}

void printLL(void)
{
    if(head == NULL)
    {
        printf("Empty Linked List");
        return;
    }
    NP temp = head;
    printf("Elements of Linked List are as follow:\n");
    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main()
{
    insFront(5);
    insFront(4);
    insFront(3);
    insFront(2);
    insFront(1);
    printLL();
    reverse();
    printf("Reversing Linked List:\n");
    printLL();
}