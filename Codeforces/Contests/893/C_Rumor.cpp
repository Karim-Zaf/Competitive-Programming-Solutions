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
set <ll> graph[N];
vi v(N,1), langots ;
bool vis [N] ;
ll sum, mrigel =0, x ,res=0;

void dfs ( ll parent, ll *lang){
    vis [parent]= 1;
    for (auto child: graph[parent]){
        if (! vis[child]){
            *lang = min (*lang , langots [child]);
            dfs ( child , lang);
        }
    }
    return;
}
void solve(){
    memset (vis , 0 ,sizeof ( vis));
    ll n  , m, root=1;
    cin >>n  >> m;
    langots .pb(0);
    for ( ll i =0 ; i  <n ; i++) {
        cin >> x ;
        langots.pb(x);
    }

    for ( ll i =1 ;i <=m ; i++){
        ll a,b;
        cin >> a >>b;
        graph[a].insert(b);
        graph[b].insert(a);   
    }
    for ( ll i =1 ; i <= n; i++){
        if ( !vis[i]){
            ll lang=langots[i];
            dfs ( i , &lang);
            // watch (lang);
            res+= lang;
        }
    }
    cout << res ; 
    
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