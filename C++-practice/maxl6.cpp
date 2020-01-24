#include<iostream>
#include<string.h>
using namespace std;
int main()

{
 char a[80] = {}, b[80]={};
 int start=0, l=0, end;
 cin.getline(a, 80); 
 int len = strlen(a);
 for (int i = 0; i < len; i++)
 {
  end = i;
  if (a[i] == ' ' || a[i] == '.')
  {

   if (l < end - start)
   {
    l = end - start;
    a[end] = 0;
    strcpy(b, &a[start]);
   }

   start = i + 1;
  }
 }cout << b << endl;
 return 0;
}
