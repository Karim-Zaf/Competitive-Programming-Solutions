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
#define int ll

const ll N = 1e6+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e18+5;

void solve(){
    int n ;
    cin >> n;
    int nw_n = n*(n-1)/2 ;
    map <int,int> mp ;
    vector <int > v(nw_n) ,s , res(n+1);
    for (auto &x: v) {
        cin >> x;
        if (!mp[x]) s.pb(x);
        mp[x]++ ;
    }
    sort (all(s));
    int curr = 0 ;
    for (int i= 1 ; i<=n ;i++){
        res[i] = s[curr];
        if (curr==s.size()){
            res[i]= 1e9 ;
            continue;
        }
        int cnt = n-i ;
        mp[s[curr]]-= cnt ;
        if (mp[s[curr]]<=0) curr++ ;
    }
    for (int i= 1; i<= n ;i++ ) cout << res [i] << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}