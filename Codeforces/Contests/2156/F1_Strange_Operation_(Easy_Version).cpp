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
    int n;
    cin >> n;

    vector<int> v(n), pos(n + 1);
    set<int> indexes;

    for (auto& x : v)cin >> x;

    for (int i = 0; i < n; i++) pos[v[i]] = i;

    for (int i = 3; i <= n; i++){ indexes.insert(i); }

    while (!indexes.empty()){
        for (auto x : set(all(indexes))){
            indexes.erase(x);

            if (x < 3 || x > n) continue;
            if (pos[x] <= min(pos[x - 1], pos[x - 2]));
            else continue;

            int one = pos[x];
            int two = pos[x - 1];
            int three = pos[x - 2];

            v[one] -= 2;
            v[two]++;
            v[three]++;

            pos[v[one]] = one;
            pos[v[two]] = two;
            pos[v[three]] = three;

            for (auto x : {v[one], v[two], v[three]}){
                indexes.insert(x);
                indexes.insert(x + 1);
            }
        }
    }

    for (auto x : v)cout << x << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
