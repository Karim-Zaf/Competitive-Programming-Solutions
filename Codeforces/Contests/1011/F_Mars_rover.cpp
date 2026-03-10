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

const int N = 1e6 + 30, MOD = 1e9 + 7, mod = 1e9 + 7, INF = 1e18 + 10;

int values[N], ans[N], child[N][2];
string operation[N];
vector <int> leafs;

int op(string oper, int a, int b = 0) {
    if (oper == "AND") return a & b;
    if (oper == "XOR") return a ^ b;
    if (oper == "OR") return a | b;
    if (oper == "NOT") return a ^ 1;
    return a;
}

void dfs(int curr = 1) {
    if (operation[curr] == "IN")return;
    if (operation[curr] == "NOT") {
        dfs(child[curr][0]);
        values[curr] = op(operation[curr], values[child[curr][0]]);
        return;
    }
    dfs(child[curr][0]);
    dfs(child[curr][1]);
    values[curr] = op(operation[curr], values[child[curr][0]], values[child[curr][1]]);
}

void work(int curr, int val) {
    if (val == values[curr]) return;
    string opp = operation[curr];
    if (opp == "IN") {
        ans[curr] ^= 1;
        return;
    }
    int one = child[curr][0], two = child[curr][1];
    if (opp == "AND") {
        if (val == 0) {
            work(one, 0);
            work(two, 0);
        } else {
            if (values[one] == 0 && values[two] == 0)return;
            if (values[one] == 0)work(one, 1);
            else work(two, 1);
        }
    }

    if (opp == "OR") {
        if (val == 0) {
            if (values[one] == 1 && values[two] == 1)return;
            if (values[one] == 1)work(one, 0);
            else work(two, 0);
        } else {
            work(one, 1);
            work(two, 1);
        }
    }

    if (opp == "XOR") {
        if (val == 0) {
            if (values[one] == 0) {
                work(one, 1);
                work(two, 0);
            } else {
                work(one, 0);
                work(two, 1);
            }
        } else {
            if (values[one] == 1 && values[two] == 1) {
                work(one, 0);
                work(two, 0);
            } else {
                work(one, 1);
                work(two, 1);
            }
        }
    }
    if (opp == "NOT") work(one, val ^ 1);
}

void Solve() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i <= n; i++) {
        cin >> operation[i] >> u;
        if (operation[i] == "IN") {
            child[i][0] = i;
            values[i] = u;
            leafs.pb(i);
        } else if (operation[i] == "NOT") {
            child[i][0] = u;
        } else {
            cin >> v;
            child[i][0] = u;
            child[i][1] = v;
        }
    }
    dfs();
    for (int i = 1; i <= n; i++) ans[i] = values[1];
    work(1, values[1] ^ 1);
    for (auto i: leafs) cout << ans[i];
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt", "r", stdin);
    freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}