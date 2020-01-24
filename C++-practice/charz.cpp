#include<iostream>
#include<string.h>
using namespace std;
int main(){
  char a[10],b[10];
   while(scanf("%s%s",a,b)!='\0'){
	   	  int i,j=0;
	  char c;
	  for(c=a[0],i=0;i<strlen(a);i++){
		  if(c<a[i]){
			  c=a[i];
			  j=i;
		  }
	  }
	  for(i=0;i<strlen(a);i++){
		  cout<<a[i];
		  if(i==j)
			  cout<<b;
	  }
cout<<endl;}
return 0;
}
