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
const ll N = 3e5+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
#define int ll
vector <int> graph[N] ,depth (N);
int up[N][30] ; 

void solve(){
    int n; 
    cin >> n ; 
    vector <ll> v(n) ; 
    long long res = 0 ; 
    for (auto &x:  v ) cin >> x ;
    sort (all(v));  
    map <ll, set <int, greater<>> > mp ;
    for(int j=0 ; j<n ;j++)
        for (int i = 20 ; i>=0 ; i--)
            if ( (v[j] & (1<<i) )==0 )
                mp[i].insert(j) ; 
    for(int j=0 ; j<n ;j++)
        for (int i = 20 ; i>=0 ; i--)
            if ( v[j] & (1<<i) ){
                if (mp[i].empty()) continue;
                int ekhor = *mp[i].begin();
                if (ekhor < j) continue;
                v[ekhor]|= (1<<i);
                v[j]-= (1<<i);
                mp[i].erase(ekhor);
            }
    for (int i= 0 ;i<n;i++) res += v[i]*v[i];
    cout << res << endl;
}

// 2241949

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}




// Failure gives you two choices: You stay down or You get up ;)