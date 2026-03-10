
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

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int n , m ;
    cin >> n >> m; 
    map <string,vector<int>> mp  ;
    map<string ,ll> jdid ;  
    vi res(n,0);
    int t[n][m+1] ; 
    for (int i = 0 ;i<n ; i++ ){
        string s = "";
        for (int j = 1 ;j<=m ; j++ ){
            cin >> t[i][j] ; 
            s+= to_string(t[i][j]);
            mp[s].pb(i) ;
        }
    }
    for (int i = 0 ;i<n ; i++ ){
        vector<int> nw ( m+1 ) ;
        for (int j =1 ;j<=m ; j++ ) nw[t[i][j]]=j ;
        string s="";
        for (ll j = 1 ;j<=m ; j++ ){
            s+= to_string(nw[j]); 
            jdid[s] = max(jdid[s],j) ;
        }
    }
    for (auto z : jdid ) {
        for (auto x:mp[z.F])
            res[x]= z.S ;
    }
    for (auto x : res ) cout << x << " ";
    cout <<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}