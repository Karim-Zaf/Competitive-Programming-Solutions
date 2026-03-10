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
    vector<int> v(n);
    for (auto& x : v)cin >> x;

    vector<multiset<int>> seti(2);
    for (auto& x : v)
        seti[x % 2].insert(x);

    auto work = [&](int x){
        vector<multiset<int>> s = seti;

        int ans = x;
        int cnt = 0;
        s[x % 2].erase(s[x % 2].find(x));
        
        x %= 2;
        x ^= 1;
        while (true){
            if (cnt && s[x].empty() && !s[x ^ 1].empty()){
                ans--;
                x ^= 1;
            }
            if (s[x].empty()) return ans;

            int curr = *prev(s[x].end());
            s[x].erase(s[x].find(curr));

            ans += curr;
            x = (ans + 1) % 2;
            cnt++;
        }
    };

    int ans = 0;
    if (!seti[1].empty())
        ans = max(ans, work(*prev(seti[1].end())));
    if (!seti[0].empty())
        ans = max(ans, work(*prev(seti[0].end())));

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
