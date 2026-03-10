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
 
 
 
const int N = 1000100 ;
const int M = 200100 ; 
vector<pair<int,int>> a(M) ;  
map<int,int> f ; 
ll ans[M] ; 
 
int calc(int x){
    int s1 = 0 , s2 = 0 ; 
    for(int p=0 ; p<3 ; p++) {
        s1+=x%10 ; 
        x/=10 ; 
    } 
 
    for(int p=0 ; p<3 ; p++) {
        s2+=x%10 ; 
        x/=10 ; 
    }
    
    return abs(s2-s1) ;
}
void solve(){
    int n ; 
    cin >> n ; 
    for(int i=1 ; i<=n ; i++){
        cin >> a[i].F ;
        a[i].S = i ;
    }
    sort(a.begin()+1,a.begin()+n+1) ; 
    
    int lst = 0 ; 
 
    for(int i=1 ; i<=n ; i++){
        for(int j=lst ; j<a[i].F ; j++){
            int g = calc(j) ; 
            f[g]++ ; 
        }
        int k = calc(a[i].F); 
        for(auto x : f){
            if(x.F<k) ans[a[i].S] += x.S; 
        }
        lst = a[i].F ;
    }
    for(int i=1 ; i<=n ; i++) cout << ans[i] << endl ; 
}
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  