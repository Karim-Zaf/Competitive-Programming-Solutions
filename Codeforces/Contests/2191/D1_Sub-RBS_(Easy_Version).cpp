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

    string nw = "";
    int cnt = 0;
    int i = 0;
    for (i = 0; i < n; i++){
        if (s[i] == ')'){ break; }
        cnt += (s[i] == '(');
        cnt -= (s[i] == ')');
        nw += s[i];
    }

    kar(nw);
    int j = i + 1;
    while (i < n && s[i] != ')')i++;

    if (i >= n) return void(cout << -1 << endl);
    nw += '(';
    cnt++;
    i++;

    while (i < n){
        cnt += (s[i] == '(');
        cnt -= (s[i] == ')');
        nw += s[i];
        i++;
    }

    kar(nw);
    if (count(all(nw), ')') < j)return void(cout << -1 << endl);
    cout << nw.size() - cnt << endl;
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
