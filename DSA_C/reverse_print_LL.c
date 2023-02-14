#include <stdio.h>

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

void rev_printLL(NP temp)
{
    if(temp == NULL){
        return;
    }
    rev_printLL(temp->next);

    printf("%d\n",temp->data);
}

int main()
{
    insFront(5);
    insFront(4);
    insFront(3);
    insFront(2);
    insFront(1);
    printLL();
    printf("Printing elements of LL in reverse order:\n");
    rev_printLL(head);
    while(head)
    {
        NP temp = head;
        head = head->next;
        free(temp);
    }
}