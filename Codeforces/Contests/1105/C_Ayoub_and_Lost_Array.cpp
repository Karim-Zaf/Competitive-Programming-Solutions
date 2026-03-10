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

const ll N = 2e5+5 , MOD =1e9+7, Q =1e5+3 ;

void solve () {
    ll n , l , r ,res = 0 ; 
    cin >> n >> l >> r ; 
    vi md(3) ;
    if (l%3) {
        if  (l%3==2){
            l++ ; 
            md[2]++  ; 
        }
        else {
            l+=2 ; 
            md[1]++ ; md[2]++ ; 
        }
    }
    if (r%3) {
        if  (r%3==2){
            r-=2 ; 
            md[2]++ ; md[1]++ ; 
        }
        else {
            r-- ; 
            md[1]++ ; 
        }
    }
    ll kadech = (r-l)/3 ; 
    md[0]+= kadech+1 ; 
    md[2]+= kadech ; 
    md[1]+= kadech ;


    ll dp[3][n+1] ;
    dp[0][1] = md[0] ;  
    dp[1][1] = md[1] ;  
    dp[2][1] = md[2] ;   
    for ( int  i =   2 ; i<=n ; i++){
        dp[0][i] = (dp[0][i-1] * md[0]%MOD +dp[1][i-1]*md[2]%MOD + dp[2][i-1]*md[1]%MOD )%MOD; 
        dp[1][i] = (dp[1][i-1] * md[0]%MOD +dp[2][i-1]*md[2]%MOD + dp[0][i-1]*md[1]%MOD )%MOD; 
        dp[2][i] = (dp[0][i-1] * md[2]%MOD +dp[1][i-1]*md[1]%MOD + dp[2][i-1]*md[0]%MOD )%MOD; 
    } 
    cout << dp[0][n] << endl; 

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