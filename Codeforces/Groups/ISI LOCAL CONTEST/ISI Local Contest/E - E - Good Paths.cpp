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
vector <ll> graph[N];
bool vis [N], vis2[N];
ll sum , k;
void dfs ( ll parent){
    vis [parent]= 1;
    // watch(parent);
    for (auto child: graph[parent]){
        if (! vis[child] && child >=k ){
            dfs(child);
            if (!vis2[child])
                sum++;
        }
    }
}
void solve(){
    ll n  , res=0;
    cin >>n >>k;
    memset(vis2,0,sizeof(vis2));
    for ( ll i =0 ;i <n ; i++){
        ll a, b ;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for ( ll i =k;i<=n; i++ ){
        vis2[i]=1;
        memset(vis,0,sizeof(vis));
        sum =0;
        dfs(i);
        res+= sum;
    }
    // watch(sum);
    cout << res <<endl;

}
int main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);freopen("outputt.txt","w",stdout);
     #endif
     FAST ;
     io() ;
     srand(time(0)) ;
     ll tt=1;
     // cin >> tt;
     while (tt--)
          solve() ;
}