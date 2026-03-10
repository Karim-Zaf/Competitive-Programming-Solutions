/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
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
#define int ll
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (n> 3){
        cout << mx * 1LL * n << endl;
        return;
    }
    if (n == 1){
        cout << a[0] << endl;
        return;
    }
    if (n == 2){
        cout << max(a[0] + a[1], 2 * abs(a[0] - a[1])) << endl;
        return;
    }
    if (mx == a.back() || mx == a[0]){
        cout << mx * 1LL * n << endl;
        return;
    }
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            vec.push_back({i, j});
    for (int i = 0; i < 3; i++){
        vec.push_back(vec[i]);
    }
    vector<int> p;
    ll ans = a[0] + a[1] + a[2];
    for (int i = 0; i < (int)vec.size(); i++)
        p.pb(i);
    do{
        vector<int> b = a;
        for (int i = 0; i < (int)p.size(); i++){
            int ind = p[i];
            int x = abs(b[vec[ind].F] - b[vec[ind].S]);
            for (int j = vec[ind].F; j <= vec[ind].S; j++)
                b[j] = x;
            ll curr = b[0] + b[1] + b[2];
            ans = max(ans, curr);
        }
    }while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}