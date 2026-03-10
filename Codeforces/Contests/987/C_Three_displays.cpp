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

const ll N = 1e18+5 , MOD =1e9+7, Q =1e5+3 ;


void solve (){ 
    ll n , mn = INF; 
    cin >> n ; 
    vi a(n) , cost(n) ; 
    ll dp[3][n] ;  
    for (ll i= 0 ; i<3 ; i++)
        for (ll j= 0 ;j <n ; j++)
             dp[i][j] = INF ;
    for (ll i= 0 ;i<n ; i++) cin >> a[i];
    for (ll i= 0 ;i<n ; i++) cin >> dp[0][i];
    for (ll j= 1 ;j <n ; j++)
        for (ll k= 0 ;k <j ; k++)
            if ( a[j]> a[k])
                dp[1][j]=min(dp[1][j], dp[0][k]+dp[0][j]);
    for (ll j= 2 ;j <n ; j++)
        for (ll k= 1 ;k <j ; k++)
            if ( a[j]> a[k] && dp[1][k]!=INF)
                dp[2][j]=min(dp[2][j], dp[1][k]+dp[0][j]);

    for (ll i =   0 ; i<n ; i++)
        mn = min ( mn , dp[2][i]) ; 
    cout <<(mn==INF ? -1 : mn ) <<endl;
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