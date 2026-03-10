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
 
void Solve() {
    string one, s;
    cin >> one >> s;
 
    vector<int> mp(26), cnt(26);
    auto get = [&](char c) { return mp[c - 'a']; };
    auto use = [&](char c) { mp[c - 'a']--; };
 
    for (auto x : one) mp[x - 'a']++;
    for (auto x : s) cnt[x - 'a']++;
    vector<string> res, wait(one.size(), ""), jdid;
 
 
    for (int i = 0; i < one.size() + 10; i++) {
        bool ok = false;
        string curr = "";
        for (int j = 0; j <= s.size(); j++) {
            if (!get(s[j]) || j + 1 < s.size() && s[j] < s[j + 1] || j == s.size()) {
                char ebda = 'a';
                if (j != s.size()) ebda = s[j] + 1;
                for (char c = ebda; c <= 'z'; c++) {
                    if (get(c) && (curr + c) > s) {
                        use(c);
                        res.pb(curr + c);
                        ok = true;
                        break ;
                    }
                }
 
                break ;
            }
            use(s[j]);
            curr += s[j];
        }
        if (!ok) break ;
    }
 
 
    cout << res.size() << endl;
    for (auto& x : res) cout << x << endl;
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
 
    freopen("volunteer.in", "r",stdin);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}