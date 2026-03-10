/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n, h;
    cin >> n >> h;

    vector<int> a(n + 1);
    int pref[n + 3][n + 2];
    int suff[n + 3][n + 2];

    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++){
        int mx = 0;
        for (int j = i; j >= 1; j--){
            mx = max(mx, a[j]);
            pref[i][j] = pref[i][j + 1] + (h - mx);
        }
    }
    for (int i = 1; i <= n; i++){
        int mx = 0;
        for (int j = i; j <= n; j++){
            mx = max(mx, a[j]);
            suff[i][j] += suff[i][j - 1] + (h - mx);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, pref[i][1] + suff[i + 1][n]);

        vector<int> st;
        for (int j = i + 1; j <= n; j++){
            while (!st.empty() && a[j] >= a[st.back()]){ st.pop_back(); }
            st.push_back(j);
            int milieu = st.front();

            ans = max(ans, pref[i][1] + suff[j][n] + suff[i + 1][milieu - 1] + pref[j - 1][milieu]);
        }
    }

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
