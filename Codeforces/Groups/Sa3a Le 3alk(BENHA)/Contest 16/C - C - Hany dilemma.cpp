//  (1/0+) WINS
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
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+7 , MOD =1e9+7, Q =1e5+3 ;

void solve(){
    ll n, res = 0,k ,  mx =-INF , ok = 0 ,x ; 
    cin >> n >> k ;
    map<ll,ll> pref ; 
    vi v ;
    vector <pair<ll,ll>> bad_contest ; 
    for (ll i= 0 ;i<n ; i++){
        cin >> x;
        if (!pref[x])v.pb(x);
        else k--;
        pref[x]++;
    }
    sort(all(v));
    n=v.size();
    vi dp(n,0) , nw(n,0);
    // watch(k);
    if (k<0) {
        cout <<-1 <<endl;return;
    }
    dp[0]= v[0]-1;
    for (ll i=1 ;i<n ;i++)
        dp[i]=v[i]-v[i-1]+dp[i-1]-1;
    for (ll i=0 ;i<n ;i++){
        nw[i]=dp[i]+(n-i-1);
        bad_contest.pb({nw[i],v[i]});
    }
    if (k>=n)
        bad_contest.pb(make_pair(k,k-n));
    sort(all(bad_contest));
    pi p = make_pair (k,0);
    // dbgpi(bad_contest);
    if (bad_contest[0].F>k){
        cout << -1 <<endl; return;
    }
    res=-INF;
    for (ll i=0 ;i<n ; i++){
        if (bad_contest[i].F<=k)
            res= max(res,bad_contest[i].S + k-bad_contest[i].F);
    }
    cout << res <<endl;
}

int main(){
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
