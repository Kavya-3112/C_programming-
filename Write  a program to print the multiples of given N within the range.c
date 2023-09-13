#include<stdio.h>
int main()
{
   int k,a,v;
   scanf("%d %d %d",&k,&a,&v);
   for(int i=k*a;i<=k*v;i=i+k)
   {
       printf("%d ",i);
   }
}
