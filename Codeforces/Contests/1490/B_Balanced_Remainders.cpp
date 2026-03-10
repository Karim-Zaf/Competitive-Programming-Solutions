#include <bits/stdc++.h>
using namespace std ;
/*int maxi(int a , int b , int c)
{
   if ( a > b && a>c)
      return a;
   else if ( b > a && b>c)
   return b;return c ;
}*/
int main ()
{
   int n ; cin >> n;
   for (int k; k<n;k++)
   {
      int c1=0,c2=0,c0=0,sum=0;
      int a; cin >>a ;
      while (a--)
      {
         int x; cin >> x;
         if (x%3==0) c0++;
         else if ( x%3==1) c1++;
         else c2++;
      }
    cout<<max(c0-c2,max(c2-c1,c1-c0))<<endl;
      
   }
}