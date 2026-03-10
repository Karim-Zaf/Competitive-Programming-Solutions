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
 
const ll N = 1e5+3, mod= 1e9 +7;
set <ll> graph[N];
vi v ;
bool vis [N], c[N];
ll sum, mrigel =0;
void dfs ( ll parent){
    vis [parent]= 1;
    ll ok =0, j=0;
    for (auto child: graph[parent]){
        
        if (c[child]&& !vis[child])
                ok++;
        if (! vis[child]){
            dfs(child);
            j++;
        }
    }
    if ( ok== j && c[parent]){
          v.pb(parent);
          mrigel=1;
    }
    
}
void solve(){
    memset (vis , 0 ,sizeof ( vis));
    memset ( c, 0 ,sizeof (c));
    ll n , root ;
    cin >>n ;
    for ( ll i =1 ;i <=n ; i++){
        ll a, b ;
        cin >> a >> b;
        c[i]=b;
        if (  a == -1 )
            root = i;
        else {
            graph[i].insert(a);
            graph[a].insert(i);
        }   
    }

    dfs(root) ;
    if (!mrigel)cout << -1 <<endl;
    else {
        sort (all(v));
        dbg ( v);
    }

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