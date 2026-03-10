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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);

    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int j = 1; j <= m; j++)cin >> b[j];
    sort(all(a));
    reverse(a.begin() + 1, a.end());
    sort(all(b));
    reverse(b.begin() + 1, b.end());

    vector<pair<int,int>> best(n + m + 1);
    int i = 1, j = 1;
    for (int sum = 1; sum <= n + m; sum++){
        if (i <= n && j <= m && a[i] > b[j]) best[sum] = {++i, j};
        else if (i <= n && j <= m && a[i] < b[j]) best[sum] = {i, ++j};
        else if (i <= n) best[sum] = {++i, j};
        else best[sum] = {i, ++j};
    }

    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 1; i <= m; i++) b[i] += b[i - 1];

    while (q--){
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0){
            cout << 0 << endl;
            continue;
        }
        auto [i,j] = best[z];
        kar(i, j);
        i--;
        j--;
        i = min(x, i);
        j = min(y, j);
        int reste = z - i - j;
        i += reste;
        j += reste;

        i = min(x, i);
        j = min(y, j);

        int sum = 0;
        if (i >= 0) sum += a[i];
        if (j >= 0) sum += b[j];
        kar(i, j)
        cout << sum << endl;
    }
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
