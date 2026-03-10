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
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
 
const ll N = 1e6+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
 
#define int ll
 
vector <int> d [N] ;
 
void solve(){
    int n , cnt = 0 , sum = 0 ; 
    cin >> n; 
    vector <int> mp(N),  v(n);
 
    for (auto &x: v)  {
        cin >> x; 
        mp[x]=1;
    }
    sort (all(v));
    for (int i= 0 ;i<n ;i++){
        for (auto x : d[v[i]]){
            if (mp[x]){
                v[i]=x;
                break;
            }
        } 
    }
    for (int i= 0  ;i<n ; i++){
        sum+= v[i];
    }    
    cout << sum << endl;
}
 
void preprocess(){
    for (int i= 1 ;i<N ;i++)
        for (int j= i ; j<N; j+=i)
            d[j].pb(i); 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    preprocess();
    cin >> test_case ;
    while (test_case--)  solve() ;
}
 
 
 
 
// Failure gives you two choices: You stay down or You get up ;)