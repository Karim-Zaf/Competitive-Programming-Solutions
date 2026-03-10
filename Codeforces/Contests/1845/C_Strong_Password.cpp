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

void solve(){
    string ch  , lef , righ, res = ""; 
    int m , p = -1; 
    cin >> ch >> m >> lef >> righ ; 
    map <char , set <int>> mp ;
    int n = ch.size();

    for (int i= 0 ;i<n ;i++)
        mp[ch[i]].insert(i) ;
 
    for (int i = 0;i<m ; i++ ){
        int mx = -1e9;
        for (char c = lef[i] ; c<=righ[i] ; c++){
            auto pos = mp[c].upper_bound(p);
            if (pos == mp[c].end()){cout << "YES\n";return;}
            mx= max (*pos,mx);
        }
        p = mx ;
    }
    cout << "NO\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}




// Failure gives you two choices: You stay down or You get up ;)