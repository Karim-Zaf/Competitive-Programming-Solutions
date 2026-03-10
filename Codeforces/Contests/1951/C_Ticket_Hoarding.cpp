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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 8e18 + 10;

void Solve() {
    int n, m, k, mrgl, sum = 0;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &x: v) cin >> x;

    sort (all(v));
    swap(m, k);
    int days = m / k;

    int modulo = m % k;
    int apart= 0, kbal = modulo;

    for (int i= 0 ; i<days ; i++){
        sum += v[i];
    }

    mrgl = k * sum ;
    mrgl += days * (days-1)/2 * k * k ;
    int divi = 0, res = 0;

    int ans = INF;
    if (m%k==0){
        kar (sum);
        cout << mrgl   << endl;
        return ;
    }

    for (int i = n-1 ; i>=days ; i--) {
        int jareb = (v[i]+ k *days) * modulo + mrgl;
        ans = min(jareb, ans);
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