#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5 + 3, M = 2e5 + 2, MOD = 998244353, MAX = 1e9, INF = 1e18;

ll ver(ll x){
  if(x == 1) return 0;
  if(x == 2) return 0;
  if(x == 3) return 1;
  if(x == 4) return 1;
  if(x == 5) return 2;
  if(x == 6) return 2;
  ll ans = x - x/4 - (x%4 > 1) - 2; 
  return ans;
}

void solve(){
  ll n;
  cin>>n;
  ll l=1, r=1e15;
  while(l<r){
    ll m = (l+r)/2;
    if(ver(m) >= n) r = m;
    else l = m+1;
  }
  cout<<l;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  ll tt = 1;
  // cin >> tt;
  while (tt--)
    solve();
  return 0;
}