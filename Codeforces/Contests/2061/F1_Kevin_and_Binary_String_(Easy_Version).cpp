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

void Solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    s = "#" + s;
    t = "#" + t;

    set<int> seti{n + 1};

    for (int i = 1; i <= n; i++){ if (s[i] != s[i - 1]){ seti.insert(i); } }

    int ans = 0, cnt = (s[1] - '0') ^ 1;

    for (int i = 1; i <= n; i++){
        if (cnt != (t[i] - '0') && seti.find(i) == seti.end())return void(cout << "-1\n");
        if (seti.find(i) != seti.end()){
            seti.erase(i);
            cnt ^= 1;
        }

        if (cnt != (t[i] - '0')){
            if (seti.size() <= 1)
                return void(cout << "-1\n");
            int dist = *next(seti.begin()) - *seti.begin();
            seti.erase(seti.begin());
            seti.erase(seti.begin());
            seti.insert(i + dist);
            cnt ^= 1;
            ans++;
        }
    }

    cout << ans << endl;
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
