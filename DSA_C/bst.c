#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NP;

NP create(int e)
{
    NP new = (NP)malloc(sizeof(struct node));
    new->data = e;
    new->left = NULL;
    new->right = NULL;
    return new; 
}

NP insert(NP temp,int e)
{   
    //if tree is empty
    if(temp == NULL)
    {
        NP new = create(e);
        return new;
    }

    if(e < temp->data)
        temp->left = insert(temp->left,e);
    else
        temp->right = insert(temp->right,e);
    return temp;
}

NP search(NP root,int e)
{
    if(root == NULL)
        return NULL;
    else if(root->data < e)
        search(root->right,e);
    else if(root->data > e)
        search(root->left,e);
    else if(root->data == e)
        return root;
}

NP minValue(NP root)
{
    NP cur = root;
    
    while(cur && cur->left)
        cur = cur->left;
    
    return cur;
}

NP delete(NP root,int e)
{
    if(root == NULL)
        return NULL;
    
    if(root->data > e)
        root->left = delete(root->left,e);
    else if(root->data < e)
        root->right = delete(root->right,e);
    else
    {
        if(root->left == NULL)
        {
            NP temp = root->left;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            NP temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            NP temp = minValue(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}


void inorder(NP temp)
{
    if(temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}

int main()
{
    NP root = create(40);
    insert(root,30);
    insert(root,50);
    insert(root,25);
    insert(root,35);
    insert(root,45);
    insert(root,60);
    NP temp = search(root,35);
    printf("%d\n",temp->data);
    inorder(root);
    printf("\nTree after deleting 45: \n");
    delete(root,45);
    inorder(root);
}