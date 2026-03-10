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

const ll N = 202;

map<string,vector<string>> graph;
map<string,int>vis;
vector <ll> va;
map <ll,ll> mp;
set <ll> s;
vector<pair<ll,ll>> vs;
int res=2,mx=0;

void solve()
{
     ll n ; cin >> n ;
     vector <ll> va(n);
     for ( auto &x: va)cin >> x;
     sort (va.begin(),va.end());
     for (ll i =1 ;i<n ; i++){
          if (va[i]-va[i-1]>1){no return;}
     }
     yes
          
     
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



