#include<stdio.h>
# include <stdlib.h>
# include <string.h>
struct student
{ char id[7]; 
char name[9]; 
int score;
};
 int main()
{
	int n,c, i,j;
	 struct student*stu, temp; 
	 while(scanf("%d%d",&n,&c)!=EOF)
			{ stu=(student*) malloc(n*sizeof(student));
			 for(i=0;i<n;i++)
				{ 
				scanf("%s%s%d",& stu[i]. id,& stu[i]. name,& stu[i]. score); 
				}
				switch(c)
					{ case 1:
						{ for(i=0;i<n;i++)
								{ for(j=i;j<n;j++)
								if(strcmp(stu[i].id, stu[j]. id)>0)
								{ 
										temp=stu[i]; 
									stu[i]=stu[j]; 
									stu[j]=temp;
									}
								}
					printf("Case 1:\n"); 
					for(i=0;i<n;i++)
					printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].score); 
					break;
				}
				case 2:
						{
						 for(i=0;i<n;i++)
						{ 
						for(j=i;j<n;j++)
							{
							 if(strcmp(stu[i]. name, stu[j]. name)>0)
						{ temp=stu[i];
						 stu[i]=stu[j]; 
						 stu[j]=temp; 
					}
						if(strcmp(stu[i]. name, stu[j]. name)==0)
						{ 
						if(strcmp(stu[i].id, stu[j].id)>0)
						{ temp=stu[i]; 
						stu[i]=stu[j];
						 stu[j]=temp;}
					
					}
					}
					}
					printf("Case 2:\n");
					for(i=0;i<n;i++)
printf("%s %s %d\n", stu[i]. id, stu[i]. name, stu[i]. score); 
 break; 
 }
  case 3:
{ for(i=0;i<n;i++)
{ for(j=i;j<n;j++)
{ if(stu[i]. score>stu[j]. score)
{ 
temp=stu[i]; 
stu[i]=stu[j];
 stu[j]=temp;
 }
 else if(stu[i]. score==stu[j]. score)
{ 
if(strcmp(stu[i]. id, stu[j]. id)>0)
{ temp=stu[i]; 
stu[i]=stu[j]; 
stu[j]=temp;
}
}
}
}
printf("Case 3:\n"); 
for(i=0;i<n;i++)
printf("%s  %s %d\n", stu[i]. id, stu[i]. name, stu[i]. score); 
break;
}
}
}
return 0;
}


 
					 
