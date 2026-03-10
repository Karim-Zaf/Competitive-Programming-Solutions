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
    ll n , m , k ; 
    cin >>n  >> m >> k ; 
    vector <pair <ll,ll>> v (k) ;
    for (ll  i= 0 ;i<k ; i++){
        ll x , y ; 
        cin >> x >> y;
        v[i]= make_pair(x,y);
    }
    ll ans = (n)*(n+1)*(m)*(m+1)/4 ;
    for (int i = 1 ; i< (1ll<<k) ;i++){
        ll min_x =1e9, min_y=1e9, max_x=0,max_y =0;
        ll a = 1 ;
        for (int j= 0 ; j< k ; j++ ){
            if ( i & ( 1ll<< j)){
                min_x= min (min_x , v[j].F);
                max_x= max (max_x , v[j].F);
                min_y= min (min_y , v[j].S);
                max_y= max (max_y , v[j].S);
                a*=-1 ;
            }
        }
        ll res = (min_x)*(min_y)*(n-max_x+1)* (m -max_y+1) ;
        ans += a*res ;
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}