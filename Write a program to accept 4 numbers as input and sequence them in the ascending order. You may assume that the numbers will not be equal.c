#include<stdio.h>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
int main()
{
    int y1, y2, y3, y4, mid1, mid2, temp, max, min;
    scanf("%i %i %i %i",&y1,&y2,&y3,&y4);
    max=MAX((MAX(y1,y2)),(MAX(y3,y4)));
    min=MIN((MIN(y1,y2)),(MIN(y3,y4)));
    mid1=MAX((MIN(y1,y2)),(MIN(y3,y4)));
    mid2=MIN((MAX(y1,y2)),(MAX(y3,y4)));
    if (mid2>mid1)
    {
        temp=mid2;
        mid2=mid1;
        mid1=temp;
    }
    printf("%i<%i<%i<%i",min,mid2,mid1,max);
}
