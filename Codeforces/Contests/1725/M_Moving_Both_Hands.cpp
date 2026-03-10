#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5 + 3, M = 2e5 + 2, MOD = 998244353, MAX = 1e9, INF = 1e18;

ll n, m, ans[N];
vector<pair<ll, ll>> adj[N], adj2[N];
bool vis[N][2];

void solve(){
  cin>>n>>m;
  for(int i=1; i<=n; i++) ans[i] = INF;
  for(ll i=1; i<=m; i++){
    ll u, v, w;
    cin>>u>>v>>w;
    adj[u].push_back({v, w});
    adj2[v].push_back({u, w});
  }
  priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, greater<pair<pair<ll, ll>, ll>>> pq; 
  pq.push({{0, 0}, 1});
  pq.push({{0, 1}, 1});
  while(!pq.empty()){
    pair<pair<ll, ll>, ll> p = pq.top();
    pq.pop();
    ll w = p.first.first, f = p.first.second, node = p.second;
    if(vis[node][f]) continue;
    vis[node][f] = true;
    ans[node] = min(ans[node], w);
    if(!f){
      for(pair<ll, ll> p : adj[node]){
        pq.push({{w+p.second, 0}, p.first});
      }
    }
    for(pair<ll, ll> p : adj2[node]){
      pq.push({{w+p.second, 1}, p.first});
    }
  }
  for(ll i=2; i<=n; i++){
    if(ans[i] == INF) cout<<-1<<' ';
    else cout<<ans[i]<<' ';
  }
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