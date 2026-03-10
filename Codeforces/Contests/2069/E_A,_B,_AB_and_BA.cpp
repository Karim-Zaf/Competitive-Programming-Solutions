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
    string s;
    map<string, int> req, mp;
    map<string, vector<int>> mp2;

    cin >> s;
    cin >> req["A"] >> req["B"] >> req["AB"] >> req["BA"];

    vector<string> v;


    char lst = '#';
    string lst_s = "";
    for (auto x: s) {
        if (x == lst) {
            v.push_back(lst_s);
            lst_s = "";
        }
        lst = x;
        lst_s += x;
    }
    v.pb(lst_s);


    int cnt = 0;
    for (auto st: v) {
        string curr = "";
        if (st.back() == st.front()) {
            curr += st.back();
            mp[curr]++;
            cnt += (int)st.size() / 2;
        } else {
            curr += st.front();
            curr += st.back();
            mp2[curr].pb((int)st.size() / 2);
        }
    }


    vector<string> st2{"AB", "BA"};
    for (int indx: {1, 0}) {
        string curr = st2[indx];
        sort(rall(mp2[curr]));
        while (!mp2[curr].empty()) {
            int lst = mp2[curr].back();
            mp2[curr].pop_back();

            int nekhou = max(0ll, min(lst, req[curr] - mp[curr]));
            mp[curr] += nekhou;
            lst -= nekhou;
            if (lst) {
                lst--;
                mp["A"]++;
                mp["B"]++;
                mp[st2[indx ^ 1]] += lst;
            }
        }
    }

    for (auto curr: {"AB", "BA"}) {
        int add = min(cnt, max(0ll, req[curr] - mp[curr]));
        cnt -= add;
        mp[curr] += add;
    }
    mp["A"] += cnt;
    mp["B"] += cnt;

    for (auto curr: {"AB", "BA"}) {
        int add = max(0ll, mp[curr] - req[curr]);
        mp[curr] -= add;
        mp["A"] += add;
        mp["B"] += add;
    }

    for (auto curr: {"AB", "BA"}) {
        assert (mp[curr] <= req[curr]);
    }

    for (auto curr: {"AB", "BA", "B", "A"}) {
        if (mp[curr] > req[curr])return void(cout << "NO\n");
    }
    kar(mp);
    cout << "YES\n";

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}