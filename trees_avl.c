#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
typedef struct Node *node;

int hgt(node nod)
{
    if(nod==NULL)
        return 0;
    return nod->height;
}

int getbalance(node nod)
{
    if(nod==NULL)
        return 0;
    int b = (hgt(nod->left)-hgt(nod->right));

    return b;
}

int max(int a,int b)
{
    return (a>b) ? a:b;
}

node newnode(int num)
{
    node newn;
    newn=(node)malloc(sizeof(struct Node));
    newn->key = num;
    newn->left=NULL;
    newn->right=NULL;
    newn->height = 1;

    return newn;
}

node leftrotate(node x)
{
    node y = x->right;
    node temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(hgt(x->left),hgt(x->right));
    y->height = 1 + max(hgt(y->left),hgt(y->right));

    return y;
}

node rightrotate(node x)
{
    node y = x->left;
    node temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = 1 + max(hgt(x->left),hgt(x->right));
    y->height = 1 + max(hgt(y->left),hgt(y->right));

    return y;
}

node insert(node nod,int num)
{
    if(nod==NULL)
    return newnode(num);

    if(num < nod->key)
        nod->left=insert(nod->left,num);
    else if(num > nod->key)
        nod->right=insert(nod->right,num);
    else    return nod;

    nod->height = 1 + max(hgt(nod->left),hgt(nod->right));

    int balance = getbalance(nod);

    if(balance < -1 && num > nod->right->key)
        return leftrotate(nod);

    else if(balance > 1 && num < nod->left->key)
        return rightrotate(nod);

    else if(balance < -1 && num < nod->right->key)
    {
        nod->right = rightrotate(nod->right);
        return leftrotate(nod);
    }

    else if(balance > 1 && num > nod->left->key)
    {
        nod->left = leftrotate(nod->left);
        return rightrotate(nod);
    }



    return nod;
}
void preorder(node root)
{
    if (root != NULL)
    {
    printf("%d->",root->key);

    preorder(root->left);

    preorder(root->right);
    }
}

node minvalue(node nod)
{
    node curr = nod;
    while(curr && curr->left)
        {
            //printf("..");
            curr = curr->left;
        }


    //printf("\n..%d..",curr->key);

    return curr;
}

node dlt(node nod,int num)
{
    if(nod==NULL)
        return nod;

    if(num < nod->key)
        nod->left = dlt(nod->left,num);
    else if(num > nod->key)
        nod->right = dlt(nod->right,num);

    else
    {
        if(nod->left == NULL)
        {
            node temp = nod->right;
            free(nod);
            return(temp);
        }
        else if(nod->right == NULL)
        {
            node temp = nod->left;
            free(nod);
            return(temp);
        }
        else
        {

            node temp = minvalue(nod->right);
            nod->key = temp->key;
            nod->right = dlt(nod->right,temp->key);
        }

    }

    if (nod == NULL)
    return nod;

  nod->height = 1 + max(hgt(nod->left),hgt(nod->right));

  int balance = getbalance(nod);
  if (balance > 1 && getbalance(nod->left) >= 0)
    return rightrotate(nod);

  if (balance > 1 && getbalance(nod->left) < 0)
    {
        nod->left = leftrotate(nod->left);
        return rightrotate(nod);
    }

  if (balance < -1 && getbalance(nod->right) <= 0)
    return leftrotate(nod);

  if (balance < -1 && getbalance(nod->right) > 0) {
    nod->right = rightrotate(nod->right);
    return leftrotate(nod);
  }

    return nod;
}

int main()
{
    node root=NULL;
    int num;
    root=insert(root,14);
    root=insert(root,17);
    root=insert(root,11);
    root=insert(root,7);
    root=insert(root,53);
    root=insert(root,4);
    root=insert(root,13);
    root=insert(root,12);
    root=insert(root,8);
    //root=insert(root,60);
    //root=insert(root,14);

    preorder(root);

    root=dlt(root,14);

    preorder(root);

}









