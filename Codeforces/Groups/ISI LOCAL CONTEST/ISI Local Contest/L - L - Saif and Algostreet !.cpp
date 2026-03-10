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
#define watch(x) cout << (#x) << " is " << (x) << endl
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
 
const ll N = 1e6+3;
 
// map<string,vector<string>> graph;
// map<string,int>vis;
// vector <ll> v, vs ,pre, primes;
// map <ll,ll> mp,par;
// set <ll> s;
ll x,y;
 
void local()
{
  #ifndef ONLINE_JUDGE
 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
}

void solve()
{
 ll n ,ans =1e18, sum =0, bigsum =0;cin >> n;
 vi v (n);
 fr ( i,0,n){
    cin >> v [i];
    sum+=v[i];
}
ll i=0;
sort ( rall (v));
for(auto x : v){
    
    // watch ( x );
    ll newsum= (n-i-1)*x - (sum - bigsum -x)+ (bigsum) - x*i ;
     // cout << newsum<< endl;
    
    ans=min (ans , newsum );
    bigsum+=x;
    i++;
    }
    cout << ans << endl;

        
}
int main()
{
    local();
     FAST ;
     io() ;
     srand(time(0)) ;
     ll tt=1;
     // cin >> tt;
     while (tt--)
          solve() ;
}