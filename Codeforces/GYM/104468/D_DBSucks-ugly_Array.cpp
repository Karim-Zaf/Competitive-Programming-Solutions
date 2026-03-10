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
 
const int N = 100100 ;
int a[N] ; 
map<int,int> f ; 
 
 
int mx=1e6 +100 ;
vector<int> spf(1e4+1,1) ;
vector<int> primes;
void sieve()
{
    ll i , j ;
    for(i=2 ; i*i<mx ; i++)
    {
        if(spf[i]==1)
        {
            primes.pb(i) ;
            for(j=i*i ; j*j<mx; j+=i) spf[j]=i   ;
        }
    }
 
}
vector<int> factorize(int n)
{
    vint a ;
    for(auto d:primes)
    {
        if((ll)(d*d)>n) break ;
        if(n%d) continue ;
        while(n%d==0) n/=d ;
        a.pb(d) ;
    }
    if(n>1)
        a.pb(n) ;
    return a ;
}
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    f.clear() ; 
    for(int i=1 ; i<=n ; i++) {
        cin >> a[i] ; 
        vector<int> fact = factorize(a[i]) ; 
        for(int i : fact) f[i]++ ; 
    }
    int ans = 0 ; 
    for(int i=1 ;i<=m ; i++){
        vector<int> fact = factorize(i) ; 
        bool ok = true ; 
        for(int i:fact){
            if(f[i]>0){
                ok = false ; 
            }
        }
        if(ok) ans++ ; 
    }
    cout << ans << endl ;
}    
 
int main()  
{
    fast 
    sieve() ; 
    ll t = 1 ; 
    cin >> t ; 
    while(t--) solve() ;
    return 0;
}