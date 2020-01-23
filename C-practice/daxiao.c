#include<stdio.h>
#include <string.h>
int main(){
      int a,b,i;
      char la[1000],lb[1000];
      gets(la);
      gets(lb);
      for(int i=0;la[i]!='\0';i++)
	      if(la[i]>='A'&&la[i]<='Z')
		      la[i]+='a'-'A';
	      for (int i=0;lb[i]!='\0';i++)
		      if(lb[i]>='A'&&lb[i]<='Z')
			      lb[i]+='a'-'A';
			      if(strcmp(la,lb)==0)
				      printf("=\n");
				          else if(strcmp(la, lb) > 0)
						  printf(">\n");
						  else
							  printf("<\n");
							  return 0;


      }
