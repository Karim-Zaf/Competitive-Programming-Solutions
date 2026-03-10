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

bool srt( pi a, pi b){
     return a.S <b.S;
}
void solve()
{
    mp.clear();
     ll N , K ; cin >> N ;
     vector <ll> v(N);
     for ( ll i =0 ; i < N ; i++){
          cin >> v[i];}
     for ( ll i =N-1 ; i>=0 ; i--){
          if (mp[v[i]]){
               cout << i+1 << endl;return;
          }
          mp[v[i]]++;
     }
     cout << 0 << endl;
          
     
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



