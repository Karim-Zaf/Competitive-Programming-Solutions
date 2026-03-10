#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}
 
const ll N = 1e6+3, mod= 1e9 +7;
vi graph[N];
bool vis [N];
void solve(){
    memset(vis,0,sizeof(vis));
    ll n , x =1; 
    cin >> n;
    vi bfs(n);
    for ( ll i=0 ; i<n-1 ;i++){
        ll a, b  ;cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for ( ll i =0 ; i<n ; i++) cin >> bfs[i];
    queue <ll> q;
    vis[1]=1;
    q.push(1);
    while (!q.empty()){
        ll i, parent= q.front(), nb=0; q.pop();
        set <ll> s;
        for (auto child: graph[parent])
            if (!vis[child])
                  nb++;
        for (i = x; i<min(x+nb,n);i++){
            q.push(bfs[i]);
            s.insert( bfs[i]);
        }
        x=i;
        for (auto child: graph[parent]){
            if (!vis[child]){
                vis[child]=1;
                if ( s.find(child)==s.end()) {no; return;}
            }
        }
    }
    yes
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
      // cin >> tt;
     while (tt--)
          solve() ;
}