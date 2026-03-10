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

const ll N = 1e5 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

void solve(){
    int n; 
    cin >> n; 
    vector <ll> v(n);
    ll res = 0 ;
    map <ll,ll> mp ;
    for (auto &x : v){
        cin >> x ; 
        mp[x]++;
    }
    res = mp[1];
    for (int i= 2  ;i <= sqrt(1e9+5) ;i++ ){
        ll prod = 1 , sum = 0 ;
        for (int k = 0  ; k <=40 && prod <=1e9+5 ;k++){
            prod *= i ;
            sum += mp[prod]*prod;
        }
        res = max (res , sum );
    }
    for (int i= 0 ;i<n ; i++)
        res = max (res , v[i]);
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}