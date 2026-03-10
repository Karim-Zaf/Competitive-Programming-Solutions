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

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int n ; 
    cin >> n; 
    set<int> s;

    vector <int> v(n),dp(2000,1e9) ;
    for (int i = 0  ;i<n ; i++ ) cin >> v[i] ;
    for (int i=  0 ;i <n ; i++){
        s.insert(v[i]);
        dp[v[i]]=min(dp[v[i]],v[i]);
        for (int j = 0 ; j<513; j++){ 
            int possible = v[i]^j ;
            if (dp[possible]>=v[i] ) continue;
            s.insert(j);
            dp[j]=min(dp[j],v[i]);
        }
    }
    s.insert(0);
    cout << s.size() <<endl;
    for (auto x : s ) cout << x << " " ; cout <<endl; 
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}