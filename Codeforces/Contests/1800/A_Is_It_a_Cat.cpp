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
 map <ll,ll> mp,par;
// set <ll> s;
ll x,y;

void solve()
{
     ll n, i=0,res =0,a=0,b=0, c=0;
     string x;
     cin >> n >> x ;
     while (i<n && (x[i]=='M' || x[i]=='m')){res=1;i++;}
     while (i<n && (x[i]=='E' || x[i]=='e')){ i++;a=1;}
     while (i<n && (x[i]=='O' || x[i]=='o')){ i++; b=1;}
     while (i<n && (x[i]=='W' || x[i]=='w')) {i++;c=1;}
     if (i==n && a && b && c && res)yes
     else no
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