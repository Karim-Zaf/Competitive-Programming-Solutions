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
    string s;
    cin >> s;
    if (s == "*")return void(cout << 1 << endl);
    if (count(all(s), '*') > 1) return void(cout << -1 << endl);

    for (int i = 1; i < s.size(); i++){ if (s[i] == '<' && s[i - 1] == '*')return void(cout << -1 << endl); }
    for (int i = 1; i < s.size(); i++){ if (s[i] == '*' && s[i - 1] == '>')return void(cout << -1 << endl); }

    int cnt = count(all(s), '*');

    string nw_s = "";
    for (auto& x : s)if (x != '*') nw_s += x;
    s = nw_s;
    for (int i = 1; i < s.size(); i++){ if (s[i] == '<' && s[i - 1] == '>')return void(cout << -1 << endl); }

    int i = -1;
    while (i + 1 < s.size() && s[i + 1] == '<')i++;
    int one = i + 1;
    int oth = s.size() - one;

    cout << max(one, oth) + cnt << endl;
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
