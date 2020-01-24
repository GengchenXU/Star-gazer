#include <iostream>
  using namespace std;
  int n,sum,maxn,i,a;
  int main()
  {
      while(scanf("%d",&n)!=EOF) {
          sum=maxn=0;
          for(i=1;i<=n;i++) 
		  scanf("%d",&a),sum+=a,maxn=max(maxn,a);
          if(maxn>sum-maxn) 
		  printf("%.1f\n",(double)sum-maxn);
        else printf("%.1f\n",sum/2.0);
     }
     return 0;
 }
