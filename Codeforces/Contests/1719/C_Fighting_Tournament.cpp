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


void solve()
{
     ll n , q, imx=1,mx=0 ; cin >> n >> q ;
     ll a[n+1];
     vector <ll> wins[n+1];
     cin >> a[1];
     ll ennemi = a[1],ienn=1;
     for ( ll i =2; i <=n; i++){
          cin >> a[i];
          // if ( a[i]>mx){
          //      mx= max (mx,a[i]);
          //      imx=i;
          // }
          if(a[i]>ennemi){
               ennemi = a[i];
               ienn =i;
               
          }
          wins[ienn].pb(i-1);
     }
     while ( q--){
          ll i , k, res=0 ; cin >> i >> k ;
          
          int org = upper_bound(wins[i].begin(), wins[i].end(), k) - wins[i].begin();
          // for ( auto x:wins[i]){
          //      if (x>k)break;
          //      else res++;
          // }
          // if (i==imx)
          //      if ( k<=n-1) cout << res<<endl;
          //      else cout << res+k-(n-1)<< endl;
          // else cout << res<<endl;
              if(k >= n) (org += (ienn == i ? k - n + 1 : 0));
        cout << org << endl;
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
      cin >> tt;
    while (tt--)
        solve() ;
}



