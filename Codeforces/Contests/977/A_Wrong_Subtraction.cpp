#include <bits/stdc++.h>
using namespace std ;
 
int main ()
{
     int x , n; cin >> x >> n ; 
     while ( n--){
         int dig = x%10;
         if (dig ==0)  x/=10;
         else x--;
     }
     cout << x;
}