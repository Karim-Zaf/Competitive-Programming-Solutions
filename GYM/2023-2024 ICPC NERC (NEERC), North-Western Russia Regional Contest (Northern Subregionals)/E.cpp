#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 100100 ; 
vector<array<ll,2>> a(N) ; 
vector<array<ll , 2>> prob ;
set<array<ll,2>> st ; 
unordered_map<ll,ll> f , g ,  g1 , g2  ; 

void solve(){
    int n;
    cin >> n ;
    
    prob.clear() ;
    f.clear() ;
    g.clear() ;
    g1.clear() ;
    g2.clear() ;
    st.clear() ;  

    for(int i = 1 ; i <= n ; i++) 
        cin >> a[i][0] >> a[i][1] ;
    
    for(int i = 2 ; i <= n ; i++) a[i][0] -= a[1][0] , a[i][1] -= a[1][1] ; 
    
    ll deltax = a[1][0] , deltay = a[1][1] ; 
    a[1][0] = a[1][1] = 0 ;
    
    for(int i = 1 ; i <= n ; i++){
        f[a[i][0] + a[i][1]]++ ; 
        g[a[i][1] - a[i][0]]++ ; 
        g1[a[i][0]]++; 
        g2[a[i][1]]++ ; 
        st.insert({a[i][0] , a[i][1]}) ; 
    }

    bool ok1 = true , ok2 = true , ok3 = true , ok4 = true ;
    for(int i = 2 ; i <= n ; i++) {
        if(a[i][0] != a[i][1]) ok1 = false ;
        if(a[i][0] != -a[i][1]) ok2 = false ;
        if(a[i][0] != 0) ok3 = false ;
        if(a[i][1] != 0) ok4 = false ;

        prob.push_back({0 , a[i][1]}) ;
        prob.push_back({a[i][0] , 0}) ;     
        
        prob.push_back({-a[i][1] , a[i][1]}) ;
        prob.push_back({a[i][1] , a[i][1]}) ;
        prob.push_back({a[i][0] , a[i][0]}) ;
        prob.push_back({a[i][0] , -a[i][0]}) ;
        
        ll pnt = -1 , b = a[i][1] + a[i][0] ; 
        
        prob.push_back({0 , b}) ; 
        prob.push_back({b , 0}) ;

        if(b % 2 == 0) {
            ll x = b / 2 , y = x ;
            prob.push_back({x , y}) ;
        } 
        pnt = 1 , b = a[i][1] - a[i][0] ; 
        prob.push_back({0 , b}) ; 
        prob.push_back({-b , 0}) ;  
        if(b % 2 == 0){
            ll x = - b / 2 , y = -x ;
            prob.push_back({x , y}) ;  
        }
    }   
    if(ok1 || ok2 || ok3 || ok4){
        cout << "YES" << endl;
        cout << deltax << " " << deltay  << endl ;
        return ; 
    }
    for(auto [x , y] : prob){
        ll cur = f[y + x] + g[y - x] + g1[x] + g2[y] ;
        if(st.find({x , y}) != st.end()) cur -= 3 ;   
        if(cur == n && x + deltax <= (int)1e9 && x + deltax >= -(int)1e9 && y + deltay <= (int)1e9 && y + deltay >= -(int)1e9) {
            cout << "YES" << endl; 
            cout << x + deltax << " " << y + deltay << endl; 
            return ; 
        }
    }
    cout << "NO" << endl;
}

int main(){
    fast 
    
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif

    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  
