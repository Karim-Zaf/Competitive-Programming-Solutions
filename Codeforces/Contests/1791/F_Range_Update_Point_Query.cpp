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
    ll n , q ;
    cin >> n >> q; 
    vector <ll> v (n) , mp(n);
    multiset <pair <ll,ll>> vp ;  
    multiset <ll> s ;
    for (ll i= 0 ;i<n ; i++) cin >> v[i] ; 
    for (ll i= 0 ;i<n ; i++) s.insert(i) ;  
    for (ll i= 0 ;i<n ; i++) s.insert(i) ; 
    for (ll i= 0 ;i<n ; i++) s.insert(i) ; 
    while (q-- ){
        ll x ; 
        cin >> x ; 
        if (x== 1 ){
            ll l , r ; 
            cin >> l >> r ; 
            vp.insert(make_pair(--l,--r)) ;
            auto it = s.lower_bound(l); 
            set <ll> erase ; 
            while (it != s.end()){
                if (*it>r ) break;
                erase.insert(*it);
                it ++ ;
            }
            for (auto x : erase){
                mp[x]++;
                s.erase(s.find(x));
            }
            continue;
        }
        cin >> x ; 
        --x ;
        ll new_x =  v[x] ;
        for (ll j= 0 ;j<mp[x] ; j++){
            string ch = to_string(new_x);
            new_x =  0 ;
            for ( auto z : ch)
                new_x+= z -'0';
        }
        cout << new_x <<endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}