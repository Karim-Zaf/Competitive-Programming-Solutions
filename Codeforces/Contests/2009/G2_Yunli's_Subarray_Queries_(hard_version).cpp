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

/*----------------------------------------Lazy--------------------------------------------*/

int Tree[4 * N], a[N];
int lazy[4 * N], n;
int upd[4 * N];

int merge(int a, int b){ return a + b; }

void unlazy(int id,int ns ,int ne){
    if (upd[id] == 0) return;
    int l = 2 * id + 1, r = 2 * id + 2;
    Tree[id] += (ne -ns +1) *lazy[id];
    lazy[l] += lazy[id], lazy[r] += lazy[id];
    upd[l] = upd[r] = 1, upd[id] = lazy[id] = 0;
}

void update(int qs, int qe, int val, int ns = 1, int ne = n, int id = 0){
    unlazy(id,ns,ne);
    if (qs > ne || qe < ns) return;
    if (qs <= ns && ne <= qe){
        lazy[id] += val, upd[id] = 1;
        unlazy(id,ns,ne);
        return;
    }
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    update(qs, qe, val, ns, md, l);
    update(qs, qe, val, md + 1, ne, r);
    Tree[id] = merge(Tree[l], Tree[r]);
}

int query(int qs, int qe, int ns = 1, int ne = n, int id = 0){
    unlazy(id,ns,ne);
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && ne <= qe)return Tree[id];
    int l = 2 * id + 1, r = 2 * id + 2, md = ns + (ne - ns) / 2;
    return merge(query(qs, qe, ns, md, l), query(qs, qe, md + 1, ne, r));
}

void Solve(){
    int q, k;
    cin >> n >> k >> q;

    for (int i = 0; i <= n; i++) update(i, i, -query(i, i));

    vector<int> v(n + 1), val(n + 1), ans(q), dp(n + 3, INF);
    map<int,int> Mp;
    multiset<int> s;
    vector<array<int, 3>> queries(q), inter;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 0; i < q; i++){
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }
    sort(rall(queries));

    for (int i = 1; i <= n; i++) val[i] = v[i] - i;

    auto ins = [&](int x){
        if (s.find(Mp[x]) != s.end())s.erase(s.find(Mp[x]));
        s.insert(++Mp[x]);
    };

    auto er = [&](int x){
        if (s.find(Mp[x]) != s.end())s.erase(s.find(Mp[x]));
        s.insert(--Mp[x]);
    };

    for (int i = 0; i < k; i++) ins(val[i]);

    for (int i = 1; i + k - 1 <= n; i++){
        ins(val[i + k - 1]);
        er(val[i - 1]);

        dp[i] = k - *prev(s.end());
    }

    auto work = [&](int i){
        array<int, 3> nw = {i, i, dp[i]};
        update(i, i, dp[i]);
        while (!inter.empty() && inter.back()[2] >= dp[i]){
            auto [l,r,val] = inter.back();
            inter.pop_back();
            update(l, r, -val + dp[i]);
            nw[1] = r;
        }
        inter.pb(nw);
    };

    int i = n - k + 1;
    for (auto [l,r,indx] : queries){
        while (i >= l){
            work(i);
            i--;
        }
        ans[indx] = query(l, r - k + 1);
    }

    for (auto x : ans) cout << x << endl;
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
