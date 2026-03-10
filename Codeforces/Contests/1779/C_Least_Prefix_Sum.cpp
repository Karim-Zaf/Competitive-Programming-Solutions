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

const ll N = 2*1e5+1;

map<string,vector<string>> graph;
// map<string,int>vis;
vector <ll> v ,vs ,pre, primes;
map <ll,ll> mp;
set <ll> s;
ll x;


void solve(){
     
     ll n, m ,mn ,sum=0, res=0, pref=0 ; cin >> n >> m; v.clear();
     fr(i,0,n){cin >> x ; v.pb(x);}
     if (n==1){cout << 0 << endl; return;}
     priority_queue <ll> p;
     rfr(i,m-1,0){
          p.push(v[i]);
          sum+=v[i];
          while ( sum > 0){
               res++;
               sum-=2*p.top();
               p.pop();
          }
     }
     priority_queue <ll> f;
     sum=0;
     fr(i,m,n){
          f.push(-v[i]);
          sum+=v[i];
          while ( sum < 0){
               res++;
               sum+=2*f.top();
               f.pop();
          }
     }
     cout << res << endl;
     
     
}
     // cout << endl;
     // sort(all(v));
     // dbg(v);
     // fr(i,0,n-m+1){
     //      if sum
     // }
     // for(auto z:mp){
     //      if (pref+e<mn){e=-e;res++;}
     //      pref+=e;
     //      cout << pref<<" ";
     // }
     
// }

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
