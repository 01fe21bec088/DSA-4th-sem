#include<stdio.h>
#include<stdlib.h>
FILE *fran,*fstack,*fpush,*fpop;
int r[100],top=-1,d;
int ran(int n)
{
    int i;
    fran=fopen("rand.txt","w");
    int r[n];
    for(i=0;i<n;i++)
    {
        r[i]=rand()%100;
        fprintf(fran,"%d\n",r[i]);
    }
    fclose(fran);

}
int push()
{
    printf("push\n");

    fstack=fopen("stack.txt","a");
    fpush=fopen("push.txt","a");

    fscanf(fran,"%d",&d);
    printf("%d\n",d);
    fprintf(fstack,"%d\n",d);
    fprintf(fpush,"%d\n",d);

    fclose(fstack);
    fclose(fpush);
    top++;
    r[top]=d;
    printf("...%d...\n",top);
}
int pop()
{
    int j;
    printf("pop");
    fstack=fopen("stack.txt","w");

    fprintf(fpop,"%d\n",r[top]);
    printf("%d\n",r[top]);
    top--;
    for(j=0;j<=top;j++)
    {
        fprintf(fstack,"%d\n",r[j]);
    }
    fclose(fstack);
}
int main()
{
    int choice,n;
    printf("enter the no of random numbers to be generated: ");
    scanf("%d",&n);
    ran(n);
    fran=fopen("rand.txt","r");
    fpop=fopen("pop.txt","a");
    while(1)
    {
        printf("1: push  2: pop  3:exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: fclose(fran);fclose(fpop); exit(0); break;
            default: printf("invalid"); break;
        }
    }

}

