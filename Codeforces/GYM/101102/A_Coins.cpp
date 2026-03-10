#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef long double ld ;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9+7   ;
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
void nop(){cout<<-1<<endl;return;}

const int N = 153 ;
int n , m , k , w;
ll dp[N][N*100] , dp1[N][N*100] ;
int a[N],  b[N] ;
ll ans = 0 ;


void solve()
{
    cin>>n>>m>>k>>w ;
    memset(dp , 0 , sizeof (dp)) ;
    memset(dp1 , 0 , sizeof (dp1)) ;
    ans = 0 ;
    for(int i = 1 ; i<=n ; i++){
        cin>>a[i] ;
    }
    for(int i = 1 ; i<=m ; i++){
        cin>>b[i] ;
    }
    dp[0][0] = 1 ;
    dp1[0][0] = 1;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 0 ; j<=w ; j++){
            dp[i][j] += dp[i-1][j] ;
            dp[i][j] %= mod ;
            if(j>=a[i]) dp[i][j] += dp[i-1][j - a[i]] ;
            dp[i][j]%=mod;
        }
    }
    for(int i = 1 ; i<=m ; i++){
        for(int j = 0 ; j<=w ; j++){
            dp1[i][j] += dp1[i-1][j] ;
            dp1[i][j]%=mod;  
            if(j>=b[i]) dp1[i][j] += dp1[i-1][j - b[i]] ;
            dp1[i][j]%= mod ;
        }
    }

    for(int mm = 0 ; mm <= w ; mm++){
        int x = w - mm ;
        if(abs(x - mm) > k) continue;
        ans = (ans + dp[n][mm] * dp1[m][x]%mod)%mod ;
    }

    cout<<ans<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin) ;
        freopen("output.out","w",stdout) ;
    #endif
    io() ;
    ll tt = 1 ;
    cin>>tt ;
    while(tt--){
        solve() ;
    }

    return 0 ;
}