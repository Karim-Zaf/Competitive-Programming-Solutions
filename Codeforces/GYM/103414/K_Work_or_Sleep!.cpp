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
 
 
double x , t ; 
 
double f(double s){
    return (((600-6*x)/t)*s + 2*x-100)*(t-s) ; 
}
double gg(double s){
    return (((6*x)/t)*s*(t-s)) ; 
}
 
double cnt(double s){
    if(s<t/6){
        return gg(s) ; 
    }else if(s<=t/3){
        return f(s) ; 
    }else{
        return 100*(t-s) ;
    }
}
 
void solve(){
    cin >> x >> t ;
    double  l = 0 , r = t ;
    while (r-l>=0.000000001){
        long double  md1 = l + (r-l)/3.0 ;
        long double  md2 = l + (2*(r-l))/3.0 ;
 
        if (cnt(md1)-cnt(md2) <= 0.000000001){
            l= md1 ;
        }else {
            r = md2 ;
        }
    }
    cout << fixed << setprecision(8) << cnt(l) << endl;
}
 
 
int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  