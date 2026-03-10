

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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1ll<<27 , MOD =1e9+7, Q =2e5+3 ; 
map<ll,ll> mp ; 

vi tab  ;

void solve (){ 
    ll n, k , sum = 0; 
    cin >> n >> k ; 
    vi v(n) , dp (64,0) ;
    for (ll i =  0 ;i<n ; i++ ) cin >> v[i] ; 
    for (ll i =  0 ;i<n ; i++ )
        for (ll j= 0 ;j<=63 ; j++){
                dp[v[i]&j]= (dp[v[i]&j]+dp[j])%mod ; 
                if ( v[i]==j ) dp[v[i]&j]= (dp[v[i]&j]+1)%MOD ; 
            }
                

    for (ll i = 0;i< 64 ; i++){
        ll cnt = 0 ;
        for (ll s = 0 ; s< 7 ; s++) if (i & (1<< s)) cnt ++ ; 
        if ( cnt == k ) sum= (sum + dp[i])%mod ; 
    }

    cout << sum <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}