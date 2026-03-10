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

vector<int> construct(int l, int r, int parity){
    vector<int> ret;
    l++;
    if (l % 2 != parity) l++;
    for (int i = l; i < r; i += 2) ret.push_back(i);

    return ret;
}

vector<int> rev(vector<int> v){
    reverse(all(v));
    return v;
}

vector<int> concat(vector<vector<int>> v){
    vector<int> ret;
    for (auto& vect : v){ for (auto x : vect) ret.push_back(x); }
    return ret;
}

vector<int> LangFord_Sequence(int n){/*
 /* Each value from 1 to n occurs exactly twice in a.
  * For each i=1,…,n, the distance between both of its occurrences is exactly i+1.
  * problem link : https://codeforces.com/gym/106063/problem/D
  * solution link : https://susam.net/langford-pairing.html?fbclid=IwY2xjawNLRMFleHRuA2FlbQIxMABicmlkETFybnlETnZTTTFUcDRQTFhaAR5e32uHyePv7ErqaN2WnDyGfipfgeIZMbYgKlGVtRrotU0cQAyioq3P3MDbEg_aem_K8WT7pkQzyBrpTiNxTSQmQ
 */
    if (n % 4 != 3 && n % 4 != 0)return {};

    int x;
    if (n % 4 == 0) x = n / 4;
    if (n % 4 == 3) x = (n + 1) / 4;

    int a = 2 * x - 1;
    int b = 4 * x - 2;
    int c = 4 * x - 1;
    int d = 4 * x;

    vector<int> p = construct(0, a, 1);
    vector<int> q = construct(0, a, 0);
    vector<int> r = construct(a, b, 1);
    vector<int> s = construct(a, b, 0);

    if (n % 4 == 0) return concat({rev(s), rev(p), {b}, p, {c}, s, {d}, rev(r), rev(q), {b}, {a}, q, {c}, r, {a}, {d}});
    if (n % 4 == 3) return concat({rev(s), rev(p), {b}, p, {c}, s, {a}, rev(r), rev(q), {b}, {a}, q, {c}, r});
}

void Solve(){
    int n;
    cin >> n;
    vector<int> res = LangFord_Sequence(n);
    if (res.empty()) return void(cout << -1 << endl);
    for (auto x : res) cout << x << " ";
    cout << endl;
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
