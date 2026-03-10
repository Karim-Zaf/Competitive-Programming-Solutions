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
    string t;
    cin >> s >> t;

    int j = 0;

    string ans = "";
    string nw_s = s;
    sort(all(nw_s));

    {
        map<char,int> mp1, mp2;

        for (auto x : t) mp1[x]++;
        for (auto x : s)mp2[x]++;
        for (char c = 'a'; c <= 'z'; c++){ if (mp2[c] > mp1[c])return void(cout << "Impossible\n"); }
    }

    sort(all(t));
    for (auto x : t){
        if (x == nw_s[j])
            j++;
        else
            ans += x;
    }

    sort(all(ans));
    string ret = "";
    int i = 0;
    for (auto x : ans){
        while (i < s.size() && s[i] <= x){
            ret += s[i];
            i++;
        }
        ret += x;
    }
    while (i < s.size()){
        ret += s[i];
        i++;
    }
    cout << ret << endl;
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
