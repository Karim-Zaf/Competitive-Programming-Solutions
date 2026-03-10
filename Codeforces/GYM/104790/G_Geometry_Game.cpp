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
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

vector<array<long long,2>> a(5) ; 
bool par = false , rec = false , sq = false, tra = false , kite = false , rh = false ;
array<long long,2> p[5] ;
long double d[5] ;
int g = 0 ; 
long long x , y  ; 
long long xx ,yy ; 

long double distance(int i,int j){
    return sqrtl(abs(a[i][0]-a[j][0])*abs(a[i][0]-a[j][0]) + abs(a[i][1]-a[j][1])*abs(a[i][1]-a[j][1])) ;
}

bool rangle(){
    return xx*x + yy*y==0.0 ; 
}
bool allrequal(){
    for(int i=1 ; i<4 ; i++) if(d[i]!=d[i+1]) return false ;
    return true ; 
}

bool gg(int i,int j){
    long long t1 = p[i][0] , t2 = p[i][1] ; 
    long long r1 = p[j][0] , r2 = p[j][1] ;
    return t1 * r2 - r1 * t2 == 0 ;
}

bool parr(){
    bool g1 = gg(1,3) ; 
    bool g2 = gg(2,4) ; 
    return  g1 && g2 ;
}
bool traa(){
    bool g1 = gg(1,3) ; 
    bool g2 = gg(2,4) ; 
    return g1 || g2 ; 
}
bool rect() {
    return par && g>0 ;
}
bool rho(){
    return allrequal() ; 
}
bool sqq(){
    return rh && g>0 ; 
}
bool kt(){
    x = a[1][0] - a[3][0] , y = a[1][1] - a[3][1] ; 
    xx = a[2][0] - a[4][0] , yy = a[2][1] - a[4][1] ; 
    return x*xx+y*yy == 0 &&  (d[1]==d[2] && d[3]==d[4] || d[2]==d[3] && d[4]==d[1]) ; 
}
void solve(){
    for(int i=1 ; i<=4 ; i++) cin >> a[i][0] >> a[i][1] ; 
    for(int i=1 ; i<4 ; i++){
        d[i] = distance(i,i+1) ; 
        p[i] = {a[i][0]-a[i+1][0],a[i][1]-a[i+1][1]} ; 
    }
    d[4] = distance(4,1) ; 
    p[4] = {a[4][0]-a[1][0],a[4][1]-a[1][1]} ; 

    x = a[2][0]-a[1][0] , y = a[2][1]-a[1][1] ; 
    xx = a[3][0]-a[2][0] , yy = a[3][1] - a[2][1] ;
    if(rangle()) g++ ; 

    par = parr() ;
    tra = traa() ;
    rec = rect() ; 
    rh = rho() ; 
    sq = sqq() ; 
    kite = kt() ;   

    if(sq) cout << "square" << endl ;
    else if(rec) cout << "rectangle" << endl ; 
    else if(rh) cout << "rhombus" << endl ;
    else if(par) cout << "parallelogram" << endl ;
    else if(tra) cout << "trapezium" << endl ;
    else if(kite) cout << "kite" << endl ; 
    else cout << "none" << endl ; 
}   


int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  