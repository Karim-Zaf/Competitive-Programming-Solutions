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
const int P =1000000 ;  
set<int> s ; 
int a[N] ; 

void solve(){
    int n ; 
    cin >> n ;
    for(int i=1 ; i<=P ; i++) s.insert(i) ; 
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i] ;
        s.erase(a[i]) ; 
    }
    int final = 1000000 ;  
    int q ; 
    cin >> q;  
    for(int i=1 ; i<=q ; i++){
        int x ; 
        cin >> x ; 
        int pos = a[x] ; 
        auto it = s.upper_bound(pos) ; 
        int new_pos ;
        if(it==s.end()){
            new_pos = ++final ;
        }else{
            new_pos = *it ; 
        }
        s.insert(pos) ; 
        s.erase(new_pos) ; 
        cout << new_pos << endl ;
        a[x] = new_pos ;
    }
}

int main()  
{
    fast 
    ll t = 1 ; 
    // cin >> t ; 
    while(t--) solve() ;
    return 0;
}