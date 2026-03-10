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

const ll N = 1e5+7;
bool vis[N];
ll dist[N];
vector <ll> graph[N] ;
vector <ll> v;
map <ll,ll> mp;
set <ll> s;

void augmBFS(ll n){
     queue<ll> q;
     q.push ( n);
     vis[n]=1;
     dist[n]=0;
     while(!q.empty()){
          ll par = q.front();
          q.pop();
          for ( auto chid: graph[par]){
               if ( !vis[chid]){
                    vis[chid]=1;
                    q.push (chid);
                    dist[chid] = dist[par]+1;
               }
          }
     }
}

void solve()
{
    ll n ,nmx, m ; cin >> n >> m ;
    if (n==m){
         cout << 0 << endl;return;
    }
    else if (n> m ){cout << n-m << endl;return;}
    else  nmx=(m-1)*2;
    
     for ( ll i =1 ; i <=nmx;i++){
          if ( i*2<=nmx) graph[i].pb(i*2);
           if ( i-1 >0) graph[i].pb(i-1);
     }
     for (int i=0 ; i<=N ; i++)
           dist[i]=INF;

     memset(vis, 0, sizeof vis);

     augmBFS(n);

     cout<<dist[m];
     
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



