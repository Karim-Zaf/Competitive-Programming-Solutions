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
 
const int N = 1510 ; 
map<tuple<string,string,int>,int> f[21] ; 
vector<string> a(N) ;
 
void solve(){
    int n ;
    cin >> n ; 
    for(int i=1 ; i<=n ; i++){
        cin >> a[i] ; 
    }
    for(int i=1; i<=n ; i++){
        for(int j=i+1 ; j<=n ; j++){
            int sz = (int)a[i].size() , sz1 = (int)a[j].size() ; 
            if(sz!=sz1) continue ; 
            int mxpref = 0 , mxsuf = 0 ; 
            int l = 0 ; 
            while(l<sz && a[i][l]==a[j][l]){
                l++ ; 
            }
            int r = sz-1 ;
            while(r>=0 && a[i][r]==a[j][r]){
                r-- ; 
            }
            if(r-l+1!=2) continue ; 
            string cur1 = "" , cur2 = "" ;
            for(int p=0 ; p<2 ; p++) {
                cur1+=a[i][p + l] ;
                cur2+=a[j][p + l] ;  
            }
            if(cur1>cur2) swap(cur1,cur2) ; 
            f[sz][{cur1,cur2,l}]++ ;
        }
    }    
    ll ans = 0 ; 
    for(int len = 3 ; len<=20 ; len++){
        for(auto x : f[len]){
            if(x.S==1) {
                ans++ ; 
            }
        }
    }
    cout << ans << endl ; 
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  