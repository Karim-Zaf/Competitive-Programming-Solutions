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

    ll n,i,j,res=0,s=0, m,x ; cin >> n >> m ;v.clear();vs.clear();
    for ( ll i =0 ; i<n ; i++){cin >> x ; v.pb( x);}
    for (ll j =0 ; j< m ; j++){cin >> x ; vs.pb(x);}
    for ( ll j=0 ; j <m ; j++){
          ll in=0;
          for (ll i=0 ;i<n;i++)
               if (v[i]<v[in])in=i;
          v[in]=vs[j];
    }
    for (auto e:v)res+=e;
    cout << res<< endl;


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



