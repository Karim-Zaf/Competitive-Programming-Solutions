#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e6+7; ll m,res=0;
bool vis[N];
ll dist[N];
vector <ll> graph[N] ;
vector <ll> v;
map <ll,ll> mp;
set <ll> s;
ll cats[N];
ll a[N];

bool lekher (ll par){
     for( auto chid : graph[par]){
          if ( !vis[chid])
          return 0; }return 1;
}
void dfs ( ll  par){
     vis [par]=1;
     if (cats[par]>m)return;
     if (lekher(par)&& cats[par]<=m)res++;
     for( auto chid : graph[par]){
          if ( cats[chid]&& !vis[chid]){
                    cats[chid]+=cats[par];
                    dfs(chid);
          }
          else if ( !vis[chid])
               dfs(chid);
     }
     return;
}
void solve()
{
     ll n ,prm; cin >> n >> m;
     memset(vis,0,sizeof vis);
     cats [N]={0};
     for ( ll j =0 ; j < n ; j++){
          cin >> cats[j];
     }
     for ( ll a, b,  j =0 ; j < n-1; j++){
          cin >> a >> b ;a--;b--;
          if (!j) prm=a;
          graph[a].pb(b);
          graph[b].pb(a);
     }
     dfs(0);
     cout << res;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout); 
    #endif 
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
     //  cin >> tt;
    while (tt--)
        solve() ;
}



