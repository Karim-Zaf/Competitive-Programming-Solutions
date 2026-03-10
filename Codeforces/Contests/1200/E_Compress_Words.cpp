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

int binpow(int a, int k, int res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a, int Mod = mod) { return binpow(a, Mod - 2); }

int mult(int a, int b, int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }

int divide(int a, int b, int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}

const int B1 = 9978, B2 = 1e9 + 3;

vector<int> pref1(1, 0), pref2(1, 0);

pair<int, int> get(int l, int r) {
    int diff1 = add(pref1[r], -pref1[l - 1]);
    diff1 = divide(diff1, binpow(B1, l-1));
    int diff2 = add(pref2[r], -pref2[l - 1]);
    diff2 = divide(diff2, binpow(B2, l-1));
    return {diff1, diff2};
}

void Solve() {
    int n;
    cin >> n;
    string ans = "", s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        pair<int, int> hash{0, 0};
        int indx = -1;
        for (int sz = 0; sz < s.size(); sz++) {
            hash.F = add(hash.F,mult(s[sz], binpow(B1, sz)));
            hash.S = add(hash.S,mult(s[sz], binpow(B2, sz)));
            int r = pref1.size() - 1;
            int l = r - sz ;
            if (l <= 0)continue;
            if (get(l,r)==hash)indx= sz;
        }
        for (int j = indx + 1; j < s.size(); j++){
            ans += s[j];

            int one = add(pref1.back(),mult (s[j],binpow(B1,pref1.size()-1)));
            int two = add(pref2.back(),mult (s[j],binpow(B2,pref1.size()-1)));

            pref1.pb(one);
            pref2.pb(two);
        }
    }
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}