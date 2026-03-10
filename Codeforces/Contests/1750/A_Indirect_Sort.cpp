#include <bits/stdc++.h>
typedef long long ll;
using namespace std ;

void solve(){
      int n ; cin >> n ;
      ll a[n];
      for (int i=0; i <n; i++)
            cin >> a [i];
      if (a[0]==1)cout <<"YES"<<endl;
      else cout <<"NO"<< endl;
}

int main ()
{
      int tt ; cin >> tt;
      while ( tt --)
            solve();
}
