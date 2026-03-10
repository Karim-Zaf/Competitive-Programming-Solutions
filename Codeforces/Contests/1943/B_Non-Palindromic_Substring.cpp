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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

/**
 * manacher(S): return the maximum palindromic substring of S centered at each point
 *
 * Input: string (or vector) of length N (no restrictions on character-set)
 * Output: vector res of length 2*N+1
 *   For any 0 <= i <= 2*N:
 *   * i % 2 == res[i] % 2
 *   * the half-open substring S[(i-res[i])/2, (i+res[i])/2) is a palindrome of length res[i]
 *   * For odd palindromes, take odd i, and vice versa
 */
template<typename V>
vector<int> manacher(const V &S) {
    int N = int(S.size());
    vector<int> res(2 * N + 1, 0);
    for (int i = 1, j = -1, r = 0; i < 2 * N; i++, j--) {
        if (i > r) {
            r = i + 1, res[i] = 1;
        } else {
            res[i] = res[j];
        }
        if (i + res[i] >= r) {
            int b = r >> 1, a = i - b;
            while (a > 0 && b < N && S[a - 1] == S[b]) {
                a--, b++;
            }
            res[i] = b - a, j = i, r = b << 1;
        }
    }
    return res;
}

vector<int> vect;

bool is_palindrome(int l, int r) {
    int len = r - l + 1;
    return vect[l + r + 1] >= len;
}


void Solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = "#" + s + "#";
    vect = manacher(s) ;
    vector<int> succ(n + 4);
    map<char, vector<int>> mp;

    for (int i = 1; i < n; i++)
        succ[i] = succ[i - 1] + (s[i] == s[i + 1]);
    for (char c = 'a'; c <= 'z'; c++) {
        mp[c].resize(n + 5);
        for (int i = 1; i <= n; i++)
            mp[c][i] = mp[c][i - 1] + (s[i] == c);
    }


    while (q--) {
        int l, r, ans = -1;
        cin >> l >> r;

        int len = r - l + 1;
        int nb = 0;
        int ch = succ[r - 1] - succ[l - 1];
        int surd = len / 2;
        int paires = surd * (surd + 1);

        for (char c = 'a'; c <= 'z'; c++) nb += ((mp[c][r] - mp[c][l - 1]) != 0);

        if (is_palindrome(l, r)) {
            if (nb == 1) ans = 0;
            else if (len % 2) {
                if (ch || nb != 2) ans = len * (len - 1) / 2 - 1;
                else ans = paires;
            } else ans = len * (len - 1) / 2 - 1;

        } else if (nb == 2 && !ch) ans = paires;
        else ans = len * (len + 1) / 2 - 1;
        cout << max(0ll, ans) << endl;
    }
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