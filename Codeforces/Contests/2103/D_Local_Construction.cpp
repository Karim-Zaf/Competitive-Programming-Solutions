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

vector<int> work(vector<int> ord, vector<int> values, int indx = 0){
    kar(ord, values, indx);
    sort(all(values));
    if (values.size() == 1) return {values[0]};
    int mn = *min_element(all(ord));

    int sz = values.size();

    deque<int> curr;
    for (auto x : values)curr.pb(x);
    vector<int> nw_values, nw_ord;

    for (int i = 0; i < sz; i++){
        if (ord[i] != mn){
            if (indx == 0){
                nw_values.pb(curr.front());
                curr.pop_front();
            }
            else{
                nw_values.pb(curr.back());
                curr.pop_back();
            }
            nw_ord.pb(ord[i]);
        }
    }

    vector<int> nw = work(nw_ord, nw_values, indx ^ 1);

    vector<int> ans(sz);
    int j = 0;
    for (int i = 0; i < sz; i++){ if (ord[i] != mn){ ans[i] = nw[j++]; } }

    if (indx == 0){
        int lst = sz - 1;
        while (lst >= 0 && ord[lst] == mn){

            ans[lst] = curr.back();
            curr.pop_back();
            lst--;
        }
    }
    else{
        int lst = 0;
        while (lst < sz && ord[lst] == mn){
            ans[lst] = curr.front();
            curr.pop_front();
            lst++;
        }
    }

    for (int i = 0; i < sz; i++){
        if (ord[i] == mn && !ans[i]){

                ans[i] = curr.back();
                curr.pop_back();
        }
    }

    return ans;
}

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto& x : v) cin >> x;
    for (auto& x : v){ if (x == -1) x = INF; }

    vector<int> values;
    for (int i = 1; i <= n; i++) values.pb(i);

    vector<int> ans = work(v, values);
    for (auto& x : ans) cout << x << " ";
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
