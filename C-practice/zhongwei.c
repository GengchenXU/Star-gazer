#include<stdio.h>
int main(){
	int a[1000],N;
	while(1){scanf("%d",&N);
		if(N<=0)
			return 0;
		
		for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N-1;i++)
		for(int j=0;j<N-1-i;j++)
			if(a[j]<a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
					if(N%2==0)
				printf("%d\n",(a[(N-1)/2]+a[(N-1)/2+1])/2);
			
			else 
				printf("%d\n",a[(N-1)/2]);
				
			
			}
					        	
			return 0;
}
