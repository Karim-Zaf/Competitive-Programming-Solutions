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
 
const ll N = 1e5+3, mod= 1e9 +7;
 
vector <ll> vv, primes;
map <ll,ll> mp;
set <ll> ss;
ll x;
    
void solve(){
    ll n , res=0 ,sum=0, mx=0, mn =1e9;
    cin >> n;
    mp.clear();
    vi v(n);
    fr ( i, 0 , n){
        cin >> v[i];
        mx= max ( mx ,v[i]); 
        mn = min ( mn ,v[i]);
        mp[v[i]]++;
    }
    map<ll, ll> dp;
    dp[mn]=mp[mn]*mn;
    fr ( i, mn , mx+1){
            dp[i]=max(dp[i-2], dp[i-3])+i*mp[i];
            res =max (res, dp[i]);
    }
    cout << res << endl;
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