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


template<class T>struct Lazy {
    int n;/**/const int ID = 0;/**/vector<T> Tree, lazy;/**/
    T merge(T a, T b) { return max(a, b); }// Merge function
    void init(int _n) { n = _n, Tree.assign(n << 2, ID), lazy.assign(n << 2, ID); }/**/
    /*Push down the update*/void unlazy(int id) {
        int l = (id << 1) + 1, r = (id << 1) + 2;
        lazy[l] += lazy[id], lazy[r] += lazy[id], Tree[l] += lazy[id], Tree[r] += lazy[id], lazy[id] = 0;
    }/*UPDATING*/void upd(int qs, int qe, int val, int ns, int ne, int id) {
        if (qs > ne || qe < ns) return;
        if (qs <= ns && ne <= qe) {/**/Tree[id] += val, lazy[id] += val;/**/return;/**/} /**/unlazy(id);
        int l = (id << 1) + 1, r = (id << 1) + 2, md = (ne + ns) >> 1;
        upd(qs, qe, val, ns, md, l), upd(qs, qe, val, md + 1, ne, r);
        Tree[id] = merge(Tree[l], Tree[r]);
    }/*Get_Update*/void upd(int qs, int qe, int val) { upd(qs, qe, val, 1, n, 0); }/**/
    /*QUERYING*/T query(int qs, int qe, int ns, int ne, int id) {
        if (qs > ne || qe < ns) return 0;
        if (qs <= ns && ne <= qe)return Tree[id];      /**/unlazy(id);
        int l = (id << 1) + 1, r = (id << 1) + 2, md = (ne + ns) >> 1;
        return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
    }/*GET_QUERY*/T query(int qs, int qe) { return query(qs, qe, 1, n, 0); }
};

vector<int> graph[N];

/*---------------------------------------EulerTour----------------------------------------------*/
int timer = 0, tin[N], tout[N];


void Euler_Tour(int curr, int parent) {
    tin[curr] = ++timer;
    for (auto child: graph[curr])
        if (child != parent)
            Euler_Tour(child, curr);
    tout[curr] = timer;
}

int color[N], ans = 0;
set<pair<int, int>> track[N];
int n;
Lazy<int> sg;

void dfs(int curr, int parent = -1) {
    int col = color[curr];
    for (auto child: graph[curr]) {
        if (child == parent) continue;
        dfs(child, curr);
    }

    sg.upd(tin[curr], tout[curr], 1);
    auto it = track[col].lower_bound({tin[curr], -INF});
    set<pair<int, int>> er;
    while (it != track[col].end() && it->F <= tout[curr]) {
        er.insert(*it);
        auto [time, node] = *it;
        sg.upd(tin[node], tout[node], -1);
        it++;
    }
    for (auto x: er) track[col].erase(x);

    track[col].insert({tin[curr], curr});


    for (auto child: graph[curr]) {
        if (child == parent) continue;
        int one = sg.query(tin[child], tout[child]);
        int two = sg.query(tin[curr], tin[child] - 1);
        two = max(two, sg.query(tout[child] + 1, tout[curr]));
        ans = max(ans, one * two);
    }

    ans = max(ans, sg.query(tin[curr], tout[curr]));
}


void init() {
    ans = timer = 0;
    sg.init(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        graph[i].clear();
        track[i].clear();
    }
}

void Solve() {
    cin >> n;
    init();
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        graph[i].pb(x);
        graph[x].pb(i);
    }
    for (int i = 1; i <= n; i++) cin >> color[i];

    Euler_Tour(1, 0);
    dfs(1);
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