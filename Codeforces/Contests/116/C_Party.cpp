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

const ll N = 1e5+3;

// map<string,vector<ll>> graph;
// map<string,int>vis;
vector <ll> vv ,vs ,pre, primes;
map <ll,ll> mp;
set <ll> s;
vector <ll> graph[N];
bool vis [N]={0}; 
ll x;
ll mx;

ll  dfs ( ll n){
    ll mx = 1;
    vis [n]=1;
    for (auto b : graph[n]){
        if ( !vis[b]){
            mx = max ( mx , dfs(b)+1);
        }
    }
    return mx;
}

void solve(){
    ll t ; cin >> t;
    ll x=0;
    vi v (t+1);
    fr ( i, 1 , t+1){
        cin >> v[i] ;
        x=v[i];
        if ( x!=-1){
            graph[i].pb( x);
            graph[x].pb (i);
        }
    }
    x=0;
    fr ( i ,1, t + 1){
        if (v[i]==-1){
            x = max (x, dfs(i));
        }
    }
    cout << x << endl;
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
