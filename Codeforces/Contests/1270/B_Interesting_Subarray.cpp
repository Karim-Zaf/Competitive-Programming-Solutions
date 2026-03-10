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

const ll N = 2*1e5+1;


map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> v,vs;
map <ll,ll> mp;
set <ll> s;

void solve()
{
     ll n,x, imax=0,imin=0 ;cin >> n ;  v.clear();
     fr(i,0,n){
          cin >> x ; v.pb(x);
     }
     
     fr(i,0,n-1){
          if (abs(v[i]-v[i+1])>1){
               cout << "YES"<<endl <<i+1<<" "<<i+2<<endl;
               return;
          }
     }
     no
}
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
       cin >> tt;
    while (tt--)
        solve() ;
}