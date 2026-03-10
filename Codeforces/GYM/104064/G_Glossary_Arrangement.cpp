#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
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
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 
 
const int N = 5010 ; 
vector<string> a(N) ;
int len[N] ,dp[N] , prec[N]; 
vector<string> st[N] ;
 
void solve(){
    int n , w ; 
    cin >> n >> w  ;
 
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i] ; 
        len[i] = (int)a[i].size() ; 
    }
 
    int l = 1 , r = n ; 
    int ans = 2e9 ; 
    while(l<=r){
        int mid = ( l + r) /2 ; 
        for(int i=1 ; i<=n ; i++) dp[i] = 2e9 ; 
        for(int i=1 ; i<=n ;i++){
            int mx = len[i] ;
            for(int j=i ; j > max(0,i - mid) ; j--){
                mx = max(mx , len[j]) ; 
                if(j-1!=0) dp[i] = min(dp[i] , mx + dp[j-1] + 1) ;
                else dp[i] = min(dp[i] , mx + dp[j-1]) ;  
            }
        }
        if(dp[n] <= w){
            ans = mid ; 
            r = mid - 1 ;
        }else l = mid + 1 ;
    }
 
    for(int i=1 ; i<=n ; i++) dp[i] = 2e9 ; 
 
    for(int i=1 ; i<=n ; i++){
        int mx = len[i] ;
        for(int j=i ; j>max(0 , i-ans) ; j--){
            mx = max(mx , len[j]) ; 
            int g = mx + dp[j-1] ; 
            if(j-1 != 0)
                g++ ; 
            if(g < dp[i]) {
                prec[i] = j-1 ; 
                dp[i] = g ; 
            }
        }
    }
    vector<array<int,2>> gg ; 
    for(int i=n ; i>=1 ; i=prec[i]){
        gg.pb({prec[i] + 1 , i}) ; 
    }
    cout << ans << " " << gg.size() << endl ;
    reverse(gg.begin() , gg.end()) ; 
    
    for(auto arr : gg){
        int l = arr[0] , r = arr[1] ;
        int x = 0 ;  
        for(int i=l ; i<=r ; i++) x = max(x , len[i]) ;
        cout << x << " " ;
        for(int i=l ; i<=r ; i++){
            while((int)a[i].length() < x) a[i]+=' ' ; 
            st[i-l].pb(a[i]) ; 
        } 
        int lenn = r - l + 1 ;
        int j = r+1 ; 
        string tmp = "" ;
        while((int)tmp.size() < x) tmp += ' ' ; 
        while(lenn < ans){
            st[j - l].pb(tmp) ;
            lenn++ ;
            j++ ;
        }
    }       
    cout << endl ; 
    for(int i=0 ; i<N ; i++){
        if(st[i].empty()) continue ; 
        for(auto x : st[i]){
            cout << x << " "  ;
        }
        cout << endl ;
    }
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  