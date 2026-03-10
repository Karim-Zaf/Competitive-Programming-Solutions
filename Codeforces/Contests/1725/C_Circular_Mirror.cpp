#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 4e5 + 3, M = 2e5 + 2, MOD = 998244353, MAX = 1e9, INF = 1e18;

ll n, m, pos[N], fact[N];
map<ll, ll> mp;

ll add(ll x, ll y){ return (x+y)%MOD; }
ll mul(ll x, ll y){ return (x*y)%MOD; }
ll poww(ll x, ll y){
  if(y == 0) return 1;
  ll ans = poww(x, y/2);
  ans = mul(ans, ans);
  if(y%2) ans = mul(ans, x);
  return ans;
}
ll inv(ll x){ return poww(x, MOD-2); }
ll bc(ll kk, ll nn){ return mul(fact[nn], inv(mul(fact[kk], fact[nn-kk]))); }

void solve(){
  cin>>n>>m;
  pos[1] = 0;
  mp[0] = 1;
  ll sum = 0;
  for(ll i=1; i<n; i++){
    ll x; cin>>x;
    sum += x;
    pos[i+1] = pos[i] + x;
    mp[pos[i+1]] = i+1;
  }
  ll x; cin>>x;
  sum += x;
  ll cnt = 0;
  if(sum %2 == 0){
    for(ll i=1; i<=n; i++){
      ll val = (pos[i]+sum/2)%sum;
      if(mp[val]) cnt++;
    }
  }
  cnt/=2;
  ll ans = 0;
  for(ll i=0; i<=cnt; i++){
    ll val = mul(mul(bc(i, m), fact[i]), bc(i, cnt));
    ll rl1 = n - 2*cnt, rl2 = cnt-i, restcolors = m-i;
    val = mul(val, mul(poww(restcolors, rl1+rl2), poww(restcolors-1, rl2)));
    ans = add(ans, val);
  }
  cout<<ans<<endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for(ll i=1; i<N; i++) fact[i] = mul(i, fact[i-1]);
  // freopen("input.txt", "r", stdin);
  ll tt = 1;
  // cin >> tt;
  while (tt--)
    solve();
  return 0;
}