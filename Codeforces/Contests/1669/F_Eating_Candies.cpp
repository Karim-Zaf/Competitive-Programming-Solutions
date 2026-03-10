#include <bits/stdc++.h>
typedef long long ll;
using namespace std ;
 
void solve(){
      ll n, s2=0,s1=0 ,comp=0,mx=0; cin >> n;
      
      ll i=-1, j=n;
      vector <ll> vc (n);
      for(int i=0; i <n;i++)
            cin >> vc[i];
      if (n==1){cout << 0 <<endl; return;}
      while (i<j){
            while(s1<s2 && i <j ){
                  i++;
                  s1+=vc[i];
                  comp++;
            }
            while(s1>s2 && i <j ){
                  j--;
                  s2+=vc[j];
                  comp++;
            }
            if (s1==s2){
                  i++;j--;
                  mx=comp;comp+=2;
                 s1+=vc[i];  s2+=vc[j];}
      }
       cout << mx << endl;
}
 
int main ()
{
int tt ; cin >> tt;
while ( tt --)
      solve();
}