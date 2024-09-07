/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

const int N = 2e6 + 30;

vector<int> graph[N], vis(N), queried(N);
int nb = 0;

void Solve() {
    int n;
    cin >> n;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    int q;
    cin >> q;
    while (q--) {
        string s;
        int x;
        cin >> s;
        if (s == "Color") {
            cin >> x;
            if (queried[x]) continue ;

            queried[x] = 1;
            nb -= vis[x];

            for (auto child : graph[x]) nb -= vis[child];

            vis[x] = 1;
            nb++;
            for (auto child : graph[x]) {
                vis[child] = 1;
                nb++;
            }
        } else cout << n - nb << endl;

    }


}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
