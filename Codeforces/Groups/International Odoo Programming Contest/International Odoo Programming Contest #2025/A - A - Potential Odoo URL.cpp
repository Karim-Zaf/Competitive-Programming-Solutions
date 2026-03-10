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

    string nw = ".odoo.com";

    while (!nw.empty() && !s.empty() && nw.back() == s.back()){
        nw.pop_back();
        s.pop_back();
    }
    if (!nw.empty())return void(cout << "No");
    if (s.size() < 4 || s.size() > 30)return void(cout << "No");
    if (s.front() == '-' || s.back() == '-') return void(cout << "No");

    for (auto x : s){
        if (!((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9') || (x == '-')))return void(cout << "No");
    }
    cout << "Yes";
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
