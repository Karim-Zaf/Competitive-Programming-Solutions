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
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template <class T>
struct Seg{ /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0;
    int n;
    vector<T> seg;
    T merge(T a, T b){ return a + b; }
    Seg(int _n){ n = _n, seg.assign(2 * n, ID); }
    void pull(int p){ seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }

    void upd(int p, T val){
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = merge(ra, seg[l++]);
            if (r & 1) rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }

    void print(int i = -1){
        while (++i < n) cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");
    }
};

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

void Solve(){
    int n, cnt = 1, ans = 0;
    string s;
    cin >> n >> s;

    s = "#" + s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i] == '1' ? 1 : -1);

    int mn = *min_element(all(pref));
    for (auto& x : pref) x += mn;

    Seg<int> sg(n + 4);

    indexed_set seti;

    vector<int> temp = pref;
    sort(all(temp));
    auto get_id = [&](int x){ return lower_bound(all(temp), x) - temp.begin(); };
    {
        int i = 0;
        int curr_id = get_id(pref[i]);
        seti.insert({pref[i], ++cnt});
        sg.upd(curr_id, sg.query(curr_id, curr_id) + pref[i]);
    }
    for (int i = 1; i <= n; i++){
        int nb_asgher = seti.order_of_key({pref[i], INF});

        int curr_id = get_id(pref[i]);
        int sum_asgher = sg.query(0, curr_id);
        ans += (nb_asgher * pref[i]) - sum_asgher;

        int nb_akber = seti.size() - nb_asgher;
        int sum_akber = sg.query(0, n + 2) - sum_asgher;
        ans += sum_akber - (nb_akber * pref[i]);

        //update
        seti.insert({pref[i], ++cnt});
        sg.upd(curr_id, sg.query(curr_id, curr_id) + pref[i]);
    }

    int sizes = 0;
    for (int i = 1; i <= n; i++){ sizes += i * (i + 1) / 2; }
    int curr_ans = ans;

    ans = (sizes - curr_ans) / 2 + curr_ans;

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
