/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

void Solve(){
    string s;
    map<char, indexed_set> mp;

    cin >> s;
    s = "#" + s;

    for (int i = 1; i < s.size(); i++) mp[s[i]].insert(i);

    int q;
    cin >> q;

    map<int, vector<array<int, 6>>> queries;
    vector<pair<int, char>> versions;
    vector<int> ans(q + 2, -1);
    for (int i = 1; i <= q; i++){
        int x;
        cin >> x;
        if (x == 1){
            int i;
            char c;
            cin >> i >> c;
            versions.push_back({i, c});
        }
        else{
            int v, l, r, k;
            char c, d;
            cin >> v >> l >> r >> k >> c >> d;
            queries[v].push_back({l, r, k, c, d, i});
        }
    }

    auto work = [&](int version){
        for (auto [l,r,k,c,d,i] : queries[version]){
            int indx = mp[c].order_of_key(l);
            int nxt_indx = INF;
            if (indx + k < mp[c].size()) nxt_indx = *mp[c].find_by_order(indx + k);
            else nxt_indx = INF;

            if (indx + k - 1 < mp[c].size()) indx = *mp[c].find_by_order(indx + k - 1);
            else indx = -INF;

            int indx2 = mp[d].order_of_key(r + 1) - 1;
            if (indx2 - k + 1 >= 0) indx2 = *mp[d].find_by_order(indx2 - k + 1);
            else indx2 = INF;

            indx2 = min(indx2, r);
            indx2 = min(indx2, nxt_indx);
            indx = max(indx, l);

            ans[i] = max(0ll, indx2 - indx);
        }
    };

    work(0);
    for (int i = 0; i < versions.size(); i++){
        auto [indx,c] = versions[i];
        mp[s[indx]].erase(indx);
        s[indx] = c;
        mp[s[indx]].insert(indx);
        work(i + 1);
    }

    for (int i = 1; i <= q; i++){
        if (ans[i] == -1) continue ;
        cout << ans[i] << endl;
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
