#include<stdio.h>
int main()
{
    long int k,sum=1;
    scanf("%ld",&k);
    for(int i=1;i<=k;i++)
    {
        sum*=i;
    
        
    }
    printf("%ld",sum);
}
