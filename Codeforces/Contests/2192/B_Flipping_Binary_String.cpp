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
    string s;
    cin >> n >> s;

    vector<int> ans;
    char curr = '1';
    int i = 0;
    for (auto& x : s){
        i++;
        char xx = x;
        if (ans.size() % 2){ xx = (x == '1' ? '0' : '1'); }
        if (xx != curr){
            ans.push_back(i);
            curr = xx;
        }
    }

    if (curr == '0'){
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
        return;
    }
    ans.clear();
    curr = '0';

    i = 0;
    for (auto& x : s){
        i++;
        char xx = x;
        if (ans.size() % 2){ xx = (x == '1' ? '0' : '1'); }
        if (xx != curr){
            ans.push_back(i);
            curr = xx;
        }
    }
    if (curr == '0'){
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
        return;
    }
    cout << -1 << endl;
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
