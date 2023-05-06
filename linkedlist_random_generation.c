#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL;
node tail=NULL;
node tail1=NULL;
node insert(int c)
{
    node newnode=(node)malloc(sizeof(struct NODE));
    if(newnode==NULL)
    {
        printf("\nNode not created");
        exit(0);
    }
    newnode->data=c;
    newnode->next=NULL;
    return newnode;
}
void read(FILE *fp)
{
    int c; node cur;
    int n;
    printf("\nEnter range: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&c);
        if(i==0)
        {
            head=insert(c);
            tail=head;
        }
        else
        {
            tail1=insert(c);
            //sort();
            tail->next=tail1;
            tail=tail->next;
        }
    }
}
void rad(FILE *fp)
{
    for(int i=0;i<1;i++)
    {
        fprintf(fp,"%d ",rand()%100);
    }
}
int main()
{
    FILE *fp;
    fp=fopen("LL.txt","w");
    if(fp==NULL)
    {
        printf("\nFile not created.");
        exit(0);
    }
    rad(fp);
    fclose(fp);
    return 0;
}
