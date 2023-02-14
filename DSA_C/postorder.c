#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node N;
typedef struct node *NP;

void postorder(NP temp)
{
    if(temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d  ",temp->data);
}

int main()
{
    N root = {8,&(N){3,&(N){1,NULL,NULL},&(N){6,&(N){4,NULL,NULL},&(N){7,NULL,NULL}}},&(N){10,NULL,&(N){14,&(N){13,NULL,NULL},NULL}}};
    postorder(&root);
    return 0;
}