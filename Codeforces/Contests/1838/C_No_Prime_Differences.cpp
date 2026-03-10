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

const ll N = 1e5 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

void solve(){
    int n , m ; 
    cin >> n >> m ; 
    int t [n][m] , p = n*m;
    for (int i = n-1 - (n%2==0); i>=0 ;i -=2 ){
        t[i][0]=p ;
        p-= m ;
    }
    p = m*(n/2) ;
    for (int i = n - 1 - (n%2) ; i>=0 ;i -=2 ){
        t[i][0]=p ;
        p-= m ;
    }

    for (int i = 0 ; i<n ;i ++ )
        for (int j = 1 ; j<m ;j ++ )
            t[i][j] = t[i][j-1]-1 ;

    for (int i = 0 ; i<n ;i ++ ){
        for (int j = 0 ; j<m ;j ++ )
            cout << t[i][j] << " " ;
        cout << endl;
    }

    cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}