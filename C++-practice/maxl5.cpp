#include <iostream>
using namespace std;
int main()
{
    int maxlen=0;
    char s[80];
   fgets(s,500,stdin); 
    int tmplen=0;
    int last=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            if(maxlen<=tmplen)
            {
                maxlen=tmplen;
                tmplen=0;
		last=i;
                            }
	         break;
	       }
        else if(s[i]!=' ')
           tmplen++;
	else if(s[i]==' ')
	    {
	    if(maxlen<=tmplen)
            {
                maxlen=tmplen;
                tmplen=0;
		last=i;
                            }
	   if(maxlen>tmplen)
	   {
		   maxlen=maxlen;
		   tmplen=0;

	   		}

		     }
   		}
        for(int i=last-maxlen;i<last;i++)
        cout << s[i] ;
    	return 0;
}

