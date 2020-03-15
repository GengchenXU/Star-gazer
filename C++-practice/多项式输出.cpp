#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main()
{
   int n,i,a[200],s,e,sum=0;
   cin>>n;
   for(i=0;i<=n;i++)
   {  cin>>a[i];
      if(a[i]==0) 
      sum++;
   }
   if(sum==n+1) cout<<0<<endl;
   else
   {
   	   for(i=n;i>=0;i--)
	   {
	   	 if(a[i]!=0)
	   	  { 
                 e=i;break;
                 }
	   }
	   for(i=0;i<=n;i++)
	   {
	   	 if(a[i]!=0)
	   	  { 
                 s=i;break;
                 }
	   } 
	   if(a[s]==1) 
	      cout<<"x^"<<n-s;
	   else if(a[s]==-1)
	      cout<<"-x^"<<n-s;
	   else
	      cout<<a[s]<<"x^"<<n-s;
	   for(i=s+1;i<e;i++)
	   {
	   	  if(a[i]!=0)
	   	  {
	   	  	if(n-i>1)
	   	  	{
		   	  	if(a[i]>0&&a[i]==1)           cout<<"+"<<"x^"<<n-i;
		   	  	else if(a[i]>0&&a[i]!=1)      cout<<"+"<<a[i]<<"x^"<<n-i;
		   	  	else if(a[i]<0&&a[i]!=-1)     cout<<"-"<<-a[i]<<"x^"<<n-i;
		   	  	else if(a[i]<0&&a[i]==-1)     cout<<"-"<<"x^"<<n-i; 
	    	}
			if(n-i==1)
	        {
		      	if(a[i]>0&&a[i]==1)           cout<<""<<"+"<<"x";
		   	  	else if(a[i]>0&&a[i]!=1)      cout<<""<<"+"<<a[i]<<"x";
		   	  	else if(a[i]<0&&a[i]!=-1)     cout<<""<<"-"<<-a[i]<<"x";
		   	  	else if(a[i]<0&&a[i]==-1)      cout<<""<<"-"<<"x";
	        }	
		 }	     
	   }
	   if(e==n)
	      {
	      	if(a[e]>0)
		    cout<<"+"<<a[e]<<endl;
		    else
		    cout<<a[e]<<endl;
	    	}
	   else
	      {
	      	if(n-e>1)
	      	{
		      	if(a[e]>0&&a[e]==1)           cout<<""<<"+"<<"x^"<<n-e;
		   	  	else if(a[e]>0&&a[e]!=1)      cout<<""<<"+"<<a[e]<<"x^"<<n-e;
		   	  	else if(a[e]<0&&a[e]!=-1)     cout<<""<<"-"<<-a[e]<<"x^"<<n-e;
		   	  	else if(a[e]<0&&a[e]==-1)      cout<<""<<"-"<<"x^"<<n-e;
	        }
	        if(n-e==1)
	        {
		      	if(a[e]>0&&a[e]==1)           cout<<""<<"+"<<"x";
		   	  	else if(a[e]>0&&a[e]!=1)      cout<<""<<"+"<<a[e]<<"x";
		   	  	else if(a[e]<0&&a[e]!=-1)     cout<<""<<"-"<<-a[e]<<"x";
		   	  	else if(a[e]<0&&a[e]==-1)      cout<<""<<"-"<<"x";
	        }
		  }
	}
	return 0;
}
 
   