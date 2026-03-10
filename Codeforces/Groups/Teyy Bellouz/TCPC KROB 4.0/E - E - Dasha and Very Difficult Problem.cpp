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
#define endl "\n"
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){ 
    int n , l , r ; 
    cin >> n >> l >> r ; 
    vector <int> a(n+1), p(n+1) , indice (n+1) ,b(n+1); 
    for (int i= 1 ; i<=n ;i++ ) cin >> a[i]; 
    for (int i= 1 ; i<=n ;i++ ) {
        cin >> p[i] ; 
        indice[p[i]] = i ; 
    }
    int prev = r+1 ; 
    for (int i= n ; i>=1 ; i--){
        int j = indice [i] ;
        b[j] = min ( a[j]+prev-1 , r) ; 
        if ( b[j]<l || b[j]>r){cout << -1 <<endl; return; } 
        prev=b[j] -a[j] ; 
    }
    for (int i= 1 ; i<=n ; i++) 
        cout << b[i] << " " ; 
    cout <<endl; 
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}