#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define ld long double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long 
const ll mod=1e9+7 ;
const ll inf = 1e9+5 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
const int N = 110 ;  
int n ; 

void solve(){    
    cin >> n ;
    int x = 0 ;
    for(int i=0 ; i<10 ; i++){
        if((1<<i)&n) x = i ; 
    } 
    
    int mx = (1<<(x+1)) - 1 ;
    ll dp[n+5][mx+5] ;
    memset(dp,0,sizeof(dp)) ;
    for(int i=1 ; i<=n ;i++){
        dp[i][i] = 1 ;
    }
    for(int s=2 ; s<=n ; s++){ 
        for(int x=0 ; x<=mx ; x++){
            for(int j=1 ; j<s ; j++){
                if(s-j>=0){ 
                    dp[s][x] = (dp[s][x] + dp[s-j][(x^j)])%mod ; 
                }
            }
        }
    }

    ll ans = 0 ; 
    for(int i=1 ; i<=mx ; i++){
        ans = (ans + dp[n][i])%mod ; 
    }
    cout << ans << endl ;
}
 
int32_t main()  
{
    fast 
    ll t = 1 ; 
    cin >> t  ;
    while(t--) solve() ;
    return 0;
}