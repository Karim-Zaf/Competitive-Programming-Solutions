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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector<int> graph[N], l(N), s(N);
int dist[N];

int n, m, h;


int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return add(a % Mod * b % Mod, Mod, Mod);
}

int gcd(int a, int b, int &x, int &y) {
    //{x,y} solution of a*x + b*y == gcd (a,b)
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int work(int a, int b) {
    // I want to calculate k such that a congru k*b (mod h)
    // b*k + h*z = a = ap *gcd(b,h)
    int ret, z;
    int g = gcd(b, h, ret, z); // calculate ret such that b*ret + h*z =gcd(g,h)
    if (a % g) return INF;
    ret = mult(ret, a / g, h / g); // to get b *ret*ap + h*z*ap = a  --> (ret*ap) is the solution

    return ret;
}

void Dijkstra(int start = 1) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, parent] = pq.top();

        pq.pop();
        if (dist[parent] < d) continue;
        for (auto child: graph[parent]) {

            int l_parent = add(l[parent], mult(d, s[parent], h), h);
            int l_child = add(l[child], mult(d, s[child], h), h);

            int a = add(l_parent, -l_child, h);
            int b = add(s[child], -s[parent], h);

            int value = work(a, b) + dist[parent] + 1;

            if (dist[child] > value) {
                dist[child] = value;
                pq.push({dist[child], child});
            }
        }
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }
}


void Solve() {
    cin >> n >> m >> h;


    init();

    for (int i = 1; i <= n; i++)cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    Dijkstra();
    cout << (dist[n] >= INF ? -1 : dist[n]) << endl;
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