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
// set <ll> s;
 
 
void solve()
{
     ll n ,ci=0,mi=0; cin >> n; 
     while (n--) {
          ll c , m ; cin >> c >> m ;
          if ( c> m )ci++;
          else if ( c< m)mi++;
     }
     if ( ci < mi)cout << "Chris";
     else if ( ci > mi)cout << "Mishka";
     else cout << "Friendship is magic!^^";
     // ll n ,ok=1; cin >>n ;
     // ll a[n],pref[n]={0},g[n];
     // fr (i,0,n) cin >> a[i];
     // fr (i,0,n) {
     //      cin >> g[i];
     //      if ( g[i]!=a[i])ok=0;
     //      if ( g[i]>a[i]){
     //      cout <<g[i]<< " "; 
     //      return;}
     //      pref[i]=a[i]-g[i];
     //      if (pref[i]<0){ no return;}
     // }
     // // if (ok){yes return;}
     // ll m ,x; cin >> m;v.clear();
     // fr(i,0,m){cin >> x; mp[x]++; v.pb(x);}
     // sort (v.begin(),v.end());
     
     // ll n,m,mn,res=0 ; cin >>n>>m; m--;
     // ll t[n],pref[n]={0},srt[n];
     //  fr(i,0,n){
     //      cin >> t[i]; srt[i]=t[i];
     //      if (!i){pref[0]=t[i];mn=t[i];}
     //      else pref[i]=pref[i-1]+t[i];
     //      mn = min (mn, pref[i]);
     // }
     // if (mn==pref[m]){cout << 0 << endl; return;}
     // sort (srt,srt+m-1);
     // sort (srt+m+1,srt+n);
     //  for(auto it : pref) cout<<it<<" ";cout<<endl;
     // // ll dif = abs(pref[m]-mn);
     // // while ( )
     
}
int main()
{
    FAST ;
    io() ;
    srand(time(0)) ;
     ll tt=1;
     //   cin >> tt;
    while (tt--)
        solve() ;
}
 
 
 