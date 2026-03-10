#include <bits/stdc++.h>
using namespace std ;
 
void solve(){
      long long n, s2=0,s1=0; cin >> n;
      while (n--){
         long long x ; cin >> x;
         if (x<0) s1+=x;
         else s2+=x;
      }
      cout << abs (abs(s1)-abs(s2))<<endl;}
 
int main ()
{
int t ; cin >> t;
while ( t--)
      solve();
 
}