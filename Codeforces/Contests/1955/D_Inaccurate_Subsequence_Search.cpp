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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


void Solve() {
    int n, m, k, cnt = 0, ans = 0;
    map<int, int> one , two ;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) {
        cin >> x;
        two[x]++ ;
    }
    for (int i= 0;i<m ; i++){
        one[a[i]]++ ;
        if (one[a[i]]<=two[a[i]]) cnt ++ ;
    }
    ans += (cnt>=k ) ;
    for (int i=m ; i<n ;i++){
        if (one[a[i-m]]<=two[a[i-m]])cnt--;
        one[a[i-m]]-- ;
        one[a[i]]++;
        if (one[a[i]]<=two[a[i]])cnt ++ ;
        ans += (cnt>=k) ;
    }
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}