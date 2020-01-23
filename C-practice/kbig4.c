#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[10000],n,i;
int cmp(const void *a, const void *b)
{ 
 return(*(int *)b-*(int *)a);
}
int main()
{int k;
 scanf("%d%d",&n,&k);
 for(i=0;i<n;i++)
 scanf("%d",&s[i]);
 qsort(s,n,sizeof(s[0]),cmp);

 printf("%d ",s[k-1]);
return(0);
}
