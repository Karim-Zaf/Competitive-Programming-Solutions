/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n + 1), ans(n + 1, -1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> nw = v;
    sort(nw.begin() + 1, nw.end());
    reverse(nw.begin() + 1, nw.end());

    if (nw != v) return void(cout << "NO\n");

    indexed_set s;
    set<int> dispo;
    for (int i = 0; i <= 3 * n; i++) dispo.insert(i);
    for (int i = 1; i <= n; i++) if (dispo.find(v[i]) != dispo.end())dispo.erase(v[i]);

    for (int i = 1; i <= n; i++){
        int x = v[i];

        int kth = n - i + 1;
        int ilfauttahti = kth - 1;
        int lzem_tahti = x - ilfauttahti;
        int tahti = s.order_of_key(x);

        if (tahti > lzem_tahti) return void(cout << "NO\n");
        if (tahti == lzem_tahti){
            ans[i] = 1e9;
            continue;
        }

        int lzem = lzem_tahti - tahti;

        auto it = dispo.lower_bound(x);
        if (lzem > 1 || it == dispo.begin())return void(cout << "NO\n");
        int curr = *prev(it);
        dispo.erase(curr);
        ans[i] = curr;

        s.insert(ans[i]);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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
