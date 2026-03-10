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
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

struct DSU{
    vector<int> sz, parent, values;
    vector<set<pair<int, int>>> graph;
    vector<set<pair<int, int>>> inside;

    void init(int n, vector<int>& a){
        values = a;
        for (int i = 0; i < n; i++){
            parent.pb(i);
            sz.pb(1);
        }
        graph.resize(n + 1);
        inside.resize(n + 1);
        for (int i = 0; i < n; i++){ inside[i].insert({values[i], i}); }
    }

    int get(int a){ return (parent[a] == a ? a : parent[a] = get(parent[a])); }

    bool unite(int a, int b){
        if ((a = get(a)) == (b = get(b))) return false;
        if (sz[a] > sz[b]){ swap(a, b); }
        for (auto x : inside[a])inside[b].insert(x);
        for (auto [ai,x] : graph[a])
            if (inside[a].find({ai, x}) == inside[a].end() && inside[b].find({ai, x}) == inside[b].end())
                graph[b].
                    insert({ai, x});

        swap(inside[a], inside[b]);
        swap(graph[a], graph[b]);
        inside[b].clear();
        graph[b].clear();
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same_set(int a, int b){ return get(a) == get(b); }
    int size(int a){ return sz[get(a)]; }
};

void Solve(){
    int n, m;
    cin >> n >> m;
    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++)cin >> values[i];
    DSU dsu;
    dsu.init(n + 1, values);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        dsu.graph[u].insert({values[v], v});
        dsu.graph[v].insert({values[u], u});
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++){ if (!values[i]){ pq.push({1, i}); } }

    while (!pq.empty()){
        auto [sz,rass] = pq.top();
        rass = dsu.get(rass);

        pq.pop();

        // nettoyage
        vector<pair<int, int>> er;
        int got_it = -1;
        for (auto [ai,x] : dsu.graph[rass]){
            if (dsu.inside[rass].find({values[x], x}) != dsu.inside[rass].end()){ er.push_back({ai, x}); }
            else if (ai <= sz){ got_it = x; break;}
            else break;
        }
        for (auto x : er) dsu.graph[rass].erase(x);
        if (got_it == -1) continue;

        dsu.unite(got_it, rass);
        pq.push({dsu.size(rass), dsu.get(rass)});
    }

    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(dsu.get(i));
    cout << (s.size() == 1 ? "YES" : "NO") << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
