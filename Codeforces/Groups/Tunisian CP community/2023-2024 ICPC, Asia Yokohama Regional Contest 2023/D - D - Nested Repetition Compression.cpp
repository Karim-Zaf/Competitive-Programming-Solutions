/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'

const int N = 205, mod = 1e9 + 7;


int binpow(int a, int k, int res = 1,int Mod = mod) {
    while (k) {
        if (k % 2) res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod) { return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}


const int B1 = 9943, B2 = 1e9 + 3;
int pref[2][N], suff[2][N], n;

void Hash(string& s) {
    n = s.size();
    for (int i = 1; i <= n; i++) {
        pref[0][i] = add(pref[0][i - 1], mult(s[i], binpow(B1, i)));
        pref[1][i] = add(pref[1][i - 1], mult(s[i], binpow(B2, i)));
    }
    suff[0][n + 1] = suff[1][n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suff[0][i] = add(suff[0][i + 1], mult(s[i], binpow(B1, n - i)));
        suff[1][i] = add(suff[1][i + 1], mult(s[i], binpow(B2, n - i)));
    }
}

pair<int, int> getHashpref(int l, int r) {
    pair<int, int> ret;
    ret.first = add(pref[0][r], -pref[0][l - 1]);
    ret.first = divide(ret.first, binpow(B1, l));

    ret.second = add(pref[1][r], -pref[1][l - 1]);
    ret.second = divide(ret.second, binpow(B2, l));
    return ret;
}

int nn;
vector<pair<int,int>> doubles[205];

vector<int> factorize[205];

string dp[205][205];
string s;

string work(int l, int r) {
    if (l == r) {
        string res = "";
        res += s[l];
        return res;
    }
    if (l > r) return "";
    string& ret = dp[l][r];

    if (ret != "") return ret;
    int curr_size = r - l + 1;
    ret = s.substr(l, curr_size);

    string jdid = s[l] + work(l + 1, r); // fallet ;
    if (jdid.size() <= ret.size()) ret = jdid;

    for (auto& [sz , cnt] : doubles[l]) {
        if (sz > curr_size) break ;
        int rep = curr_size / sz;
        rep = min(rep, cnt);
        if (rep == 1) continue;
        string interm = "";

        if (l + rep * sz - 1 != r) {
            interm = work(l, l + rep * sz - 1) + work(l + rep * sz, r);
            if (interm.size() <= ret.size()) ret = interm;
            continue ;
        }

        bool ok = true;
        for (auto x : factorize[rep]) interm += to_string(x) + "(";
        for (auto x : factorize[rep]) ok &= to_string(x).size() <= 1;

        interm += work(l, l + sz - 1);

        for (auto x : factorize[rep]) interm += +")";

        interm += work(l + rep * sz, r);
        if (interm.size() <= ret.size() && ok) ret = interm;
    }

    for (int i = l - 1; i <= r; i++) {
        string interm = work(l, i) + work(i + 1, r);
        if (interm.size() <= ret.size()) ret = interm;
    }
    return ret;
}

void Solve() {
    cin >> s;

    nn = s.size();
    s = "#" + s;
    Hash(s);


    for (int l = 1; l <= nn; l++) {
        for (int sz = 1; sz <= nn; sz++) {
            int r = l + sz - 1;
            if (r > nn) break ;
            int cnt = 0;
            for (int j = l; j <= nn; j += sz) {
                int nw_r = j + sz - 1;
                if (nw_r > nn) break ;
                if (getHashpref(l, r) != getHashpref(j, nw_r)) break ;
                cnt++;
            }
            if (cnt != 1) doubles[l].push_back({sz, cnt});
        }
    }

    for (int i = 1; i <= n + 2; i++) {
        int x = i;
        for (int j = 9; j >= 2; j--) {
            while (x % j == 0) {
                x /= j;
                factorize[i].push_back(j);
            }
        }
        if (x > 1) factorize[i].push_back(x);
    }

    cout << work(1, nn);

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
