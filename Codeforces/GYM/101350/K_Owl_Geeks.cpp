/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)   
#endif
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 1e7 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;


void solve(){
    ll a ,b , n ; 
    cin >> a >> b >> n ; 
    vector <ll> mp (10);
    set<ll> s ;
    ll sol = ((long double)(-b)+ sqrtl(b*b + 4*a*n))/(long double)(2*a);

    function <ll(ll)> f = [&]( ll x ) {return a*x*x + b*x;};

    ll x = 1 ;

    while (true) {
        ll curr =f(x++);
        if (curr > n) break;
        s.insert(curr);
    }  

    if (s.empty()) {non return;}

    for (auto ss :s) {
        string curr = to_string(ss) ;
        vector <ll> occ (10) ;
        for (auto c : curr ) occ[c-'0']++ ;
        ll mx = 0 ;
        for (ll j= 0 ; j<10 ; j++)
            mx = max (mx ,occ[j]);
        for(ll j= 0 ; j<10 ; j++){
            if (occ[j]==mx)
                mp[j]++ ;
        }
    }
    ll res = 0 ;
    for(ll j= 0 ; j<10 ; j++)
        if (mp[j]>mp[res])res = j ;
    cout << res <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}