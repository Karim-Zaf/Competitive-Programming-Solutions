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

void solve (){  
    ll n , ok = 0, res = 0 , verif = 1, b = 0 ; 
    cin >> n; 
    for (ll i = 27 ; i>=0 ; i--){
        ll curr = 1<<i ; 
        if ( curr & n && !ok) ok = i;
        if (ok) res += curr ;
        if ( ok && i > 0 ) verif &= ( (n & curr) && n &(1<<(i-1)) ) ; 
    }
    if (!verif ) cout << res<<endl; 
    else cout << mp[n]<<endl;
}

void preprocess(){
    ll curr =0 ; 
    for (ll i = 0 ; i<=27 ; i++){
        curr += 1<<i ; 
        for (ll j = 1 ; j*j< curr ; j++){
            mp[curr]=max(mp[curr], __gcd ( curr^j ,curr&j));
            if (curr%j || curr%j==0 && curr/j >=curr) continue;
            ll jj = curr/j ;  
            mp[curr]=max(mp[curr], __gcd ( curr^jj ,curr&jj)); 
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    cin >> test_case ; 
    preprocess() ; 
    while (test_case--)  solve() ;
}