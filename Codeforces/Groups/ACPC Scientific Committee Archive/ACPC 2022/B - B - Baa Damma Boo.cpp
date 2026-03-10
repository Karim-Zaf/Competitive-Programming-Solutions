//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
//Geometry
struct point{
    ll x , y ; 
    point() {}
    point(ll x , ll y) {
        this->x = x;
        this->y = y ;
    }
    void read(){
        cin >> x >> y;
    }
    void print() {
        cout << x << " " << y << endl;
    }
    bool equal(const point &p) {
        return p.x == x && p.y == y ;
    }
};
typedef point pt ; 
 
point sub(const point p1 , const point p2){
    return {p1.x - p2.x , p1.y - p2.y} ; 
}
 
 
ll cross(const point p1 , const point p2){
    return p1.x * p2.y - p1.y * p2.x ; 
}
 
ll dot(const point p1 , const point p2){
    return p1.x * p2.x + p1.y * p2.y ; 
}
 
int sgn(ll x){
    if(x > 0) return 1 ;
    if(x == 0) return 0 ;
    return -1 ;
}
 
ll dist(pt p1 , pt p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) ; 
}
 
bool inside(pt pt1 , pt pt2 , pt pt3){
    pt p1 = sub(pt2 , pt1) ;
    int new_x = p1.x , new_y = p1.y ;
    p1 = point(-new_y , new_x) ;
    if(sgn(cross(p1 , sub(pt3 , pt1))) != sgn(cross(p1 , sub(pt3 , pt2)))) return true ;
    return false ;
}
 
void solve(){
    int n ;
    cin >> n ;
    vector<pt> vec(n) ;
    for(int i = 0 ; i < n ; i++) vec[i].read();
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            map<ll,int> f1 , f2 ;
            map<ll,int> g1 , g2 ;
            int cnt1 = 0 , cnt2 = 0;
            for(int k = 0 ; k < n ; k++){
                if(k == i || k == j) continue ;
                ll c = cross(sub(vec[k] , vec[i]) , sub(vec[j] , vec[i])) ;
                ll d1 = dot(sub(vec[k] , vec[i]) , sub(vec[j] , vec[i])) ;
                ll d2 = dot(sub(vec[k] , vec[j]) , sub(vec[j] , vec[i])) ;
                if(c == 0) continue ;
                if(c > 0){
                    if(d1 == 0){
                        f1[dist(vec[k] , vec[i])]++ ;
                    }
                    else if(d2 == 0){
                        f2[dist(vec[k] , vec[j])]++ ;
                    }else {
                         if(inside(vec[i] , vec[j] , vec[k])) 
                            cnt1++ ;
                    }
                }else{
                    if(d1 == 0){
                        g1[dist(vec[k] , vec[i])]++ ;
                    }
                    else if(d2 == 0){
                        g2[dist(vec[k] , vec[j])]++ ;
                    }else {
                        if(inside(vec[i] , vec[j] , vec[k])) 
                            cnt2++ ;
                    }
                }
            }
            for(auto x : f1){
                if(f2.count(x.F)){
                    ans += cnt2 ;
                }
            }
            for(auto x : g1){
                if(g2.count(x.F)) {
                    ans += cnt1 ;
                }
            }
        }
    }
    cout << ans << endl;
}
 
int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}