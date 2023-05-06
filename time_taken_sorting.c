//Author: Satwik Bewoorkar
//SEM: 04
#include<stdio.h>
#include<time.h>
int main()
{
    FILE *fp1,*fp2;
    int n,i,b;
    time_t isec,fsec,f;
    isec=time(NULL);
    fp1=fopen("ran.txt","w");
    printf("elements: ");
    scanf("%d",&n);

    int r[n];
    for(i=0;i<n;i++)
    {
        r[i]=rand();
        //printf("\n%d",r[i]);
        fprintf(fp1,"%d\n",r[i]);
    }
    fclose(fp1);


    fp1=fopen("ran.txt","r");

    int c;

     fscanf(fp1,"%d",&n);
     printf("%d",n);
     int a[n];
     for(i=0;i<n;i++)
     {
        fscanf(fp1,"%d",&b);
        a[i]=b;
        //printf("\n%d",a[i]);
     }
     printf("\nreversed array");

//reversing

     int z[n];
     for(i=0;i<n;i++)
     {
         z[i]=a[n-i-1];
         //printf("\n%d",z[i]);
     }
     fclose(fp1);

     fp2=fopen("rand11.xlsx","w");
     for(i=0;i<n;i++)
     {
         fprintf(fp2,"\n%d",r[i]);
     }
     fclose(fp2);

     fsec=time(NULL);
    f=fsec-isec;
    printf("\n..%d..",f);




}

