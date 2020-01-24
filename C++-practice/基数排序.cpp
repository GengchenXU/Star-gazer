#include <iostream>
#include<cstring>
using namespace std;
int main()
{
 int n, a[500], g[500], s[500], b[500];
 cin >> n;
 for (int i = 0; i < n; i++)
  cin >> a[i];
 for (int i = 0; i < n; i++)
 {
 	
  b[i] = a[i] / 100;
  s[i] = (a[i] - (b[i] * 100)) / 10;
  g[i] = a[i] - b[i] * 100 - s[i] * 10;
 }
 
 for (int i = 0; i < n; i++)
 {
  for (int j = 1; j < n - i; j++)
  {
   if (g[j - 1] > g[j])
   {
    int temp = g[j];
    g[j] = g[j - 1];
    g[j - 1] = temp;
    temp = a[j];
    a[j] = a[j - 1];
    a[j - 1] = temp;
    /*temp = b[j];
    b[j] = b[j - 1];
    b[j - 1] = temp;
    temp = s[j];
    s[j] = s[j - 1];
    s[j - 1] = temp;*/
   }
  }
 }
  for (int i = 0; i < n - 1; i++)
  {
   cout << a[i] << ' ';
  }
  cout << a[n - 1] << endl;
 for (int i = 0; i < n; i++)
 {
  for (int j = 1; j < n - i; j++)
  {
   if (s[j - 1] > s[j])
   {
    int temp; /*= g[j];
    g[j] = g[j - 1];
    g[j - 1] = temp;*/
    temp = a[j];
    a[j] = a[j - 1];
    a[j - 1] = temp;
    /*temp = b[j];
    b[j] = b[j - 1];
    b[j - 1] = temp;*/
    temp = s[j];
    s[j] = s[j - 1];
    s[j - 1] = temp;
   }
  }
 }
 for (int i = 0; i < n-1; i++)
 {
  cout << a[i] << ' ';
 }
 cout << a[n-1]<<endl;
 for (int i = 0; i < n; i++)
 {
  for (int j = 1; j < n - i; j++)
  {
   if (b[j - 1] > b[j])
   {
    int temp; /*= g[j];
    g[j] = g[j - 1];
    g[j - 1] = temp;*/
    temp = a[j];
    a[j] = a[j - 1];
    a[j - 1] = temp;
    temp = b[j];
    b[j] = b[j - 1];
    b[j - 1] = temp;
   /* temp = s[j];
    s[j] = s[j - 1];
    s[j - 1] = temp;*/
   }
  }
 }
 for (int i = 0; i < n - 1; i++)
 {
  cout << a[i] << ' ';
 }
 cout << a[n - 1] << endl;
 return 0;
}
