#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
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
const ll mod=1e9+7 ;
const ll inf = 1e9+5 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
const int N = 200100 ; 
ll a[N] ; 
 
void solve(){
    int a , b ; 
    cin >> a >> b ; 
    bool signa = false , signb=false ; 
    if(a<=0) signa = true ; 
    if(b<=0 ) signb = true ;   
    a = abs(a) ; 
    b = abs(b) ; 
    vector<int> arr ,brr ;
    ll cur = 1 ; 
    while(a>0){
        if(a%10!=0) arr.pb((a%10) * cur) ; 
        cur*=10 ; 
        a/=10 ;
    }
    cur = 1 ; 
    while(b>0){
        if(b%10!=0) brr.pb((b%10)*cur) ; 
        cur*=10 ; 
        b/=10 ; 
    }
    for(int i=0 ; i<(int)(arr.size()) ; i++){
        for(int j=0 ; j<(int)(brr.size()) ; j++){
            if(signa){
                cout << -arr[i] ;
            }else cout << arr[i] ;
            if(signb){
                cout << " x " << -brr[j]  ; 
            }else cout << " x " << brr[j]  ;
            if(i+1==(int)(arr.size()) && j+1==(int)(brr.size())) continue ; 
            cout << " + " ;
        }
    }
    cout << endl ;
}    
 
int main()  
{
    fast 
    ll t = 1 ; 
    cin >> t ; 
    while(t--) solve() ;
    return 0;
}