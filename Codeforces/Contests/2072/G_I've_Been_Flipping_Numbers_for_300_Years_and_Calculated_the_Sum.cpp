/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 2e5 + 30, MOD = 1e9 + 7, mod = 1e9 + 7, INF = 1e18 + 10;

long long binpow(long long a, long long k) {
    long long res = 1;
    while (k) {
        if (k % 2)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        k /= 2;
    }
    return res;
}

ll modinv(long long a) { return binpow(a, MOD - 2); }

ll divide(ll a, ll b) {
    a %= MOD;
    b = modinv(b) % MOD;
    long long c = a * b;
    c %= MOD;
    return c;
}

int add(int u, int v) {
    return ((u + v) % mod + mod) % mod;
}

int mult(int u, int v) {
    u %= mod;
    v %= mod;
    return u * v % mod;
}

int work(int x, int base) {
    vector<int> rest;

    while (x) {
        rest.pb(x % base);
        x /= base;
    }

    reverse(all(rest));
    int ret = 0, b = 1;
    for (auto &curr: rest) {
        ret = add(ret, mult(b, curr));
        b = mult(b, base);
    }
    return ret;
}

int sum(int lef, int righ) {
    int one = divide(mult(lef, lef - 1), 2);
    int two = divide(mult(righ, righ + 1), 2);
//    cout << add(two,-one)<< endl;
    return add(two, -one);
}

int sum_square(int lef, int righ) {
    int one = divide(mult(mult(lef, lef - 1),add(mult(2,(lef-1)),+1)), 6);
    int two = divide(mult(mult(righ, righ + 1),add(mult(2,righ),+1)), 6);
    return add(two, -one);
}


void Solve() {
    int n, k, ans = 0;
    cin >> n >> k;


//    if (n == 1) return void ( cout << k-1 << endl);
    int sq = sqrt(n);

    for (int i = 2; i <= min(sq, k); i++) {
        ans = add(ans, work(n, i));
        //cout << "i : " << i<< " , ans : "<< work(n,i) << endl;
    }

    if (sq < k) {
        int curr_ans = 0;
        int lef = sq + 1;
        while (lef <=n) {
            int curr = n / lef;
            int righ= n / (curr);
            righ = min(righ, k);
            curr_ans = add(curr_ans, mult(curr, righ - lef + 1));

            curr_ans = add(curr_ans, mult(n,sum(lef,righ)));
            curr_ans = add(curr_ans, -mult(curr,sum_square(lef,righ)));

            if (righ == k) break;
           // cout << "righ : " << righ << " , curr : " <<  curr << " , lef : " << lef << endl;
            lef = righ + 1;
        }
        ans = add(ans, curr_ans);
    }

    if (k > n) {
        int curr = 0;

        curr = mult(n, (k - n));
        ans = add(ans, curr);
    }

    cout << ans << endl;
}

/*
3
7594
9
6
1
33471
10
2006
120792461
584502117
775
46058362
 * */
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("D:/Users/Bureau/KARIM/Code Forces/setup/input.txt", "r", stdin);
    freopen("D:/Users/Bureau/KARIM/Code Forces/setup/output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
