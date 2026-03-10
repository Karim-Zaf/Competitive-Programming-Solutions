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
#define endl '\n'

const int N = 1 << 19, mod = 1e9 + 7;

vector<int> mask(71), vis(71);
int dp[71][N];

void sieve() {
    int cnt = 0;
    for (int i = 2; i <= 70; i++) {
        if (vis[i]) continue;
        for (int j = i; j <= 70; j += i) {
            int x = j, nb = 0;
            while (x % i == 0) {
                x /= i;
                nb++;
            }
            if (nb % 2) mask[j] |= 1 << cnt;
            vis[j] = 1;
        }
        cnt++;
    }
}

ll binpow(ll a, ll k, ll res = 1, int Mod = mod) {
    while (k) {
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

ll mult(ll a, ll b, int Mod = mod) {
    b %= Mod;
    return (a % Mod * b % Mod);
}

ll add(ll a, ll b, int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }


void Solve() {
    // representing each prime with a bit (19 bits)
    // the problem is becoming how many subset having xor = 0 --> we'll use dp

    int n;
    cin >> n;
    sieve();
    vector<int> mp(71), v(n);

    for (auto &x: v) {
        cin >> x;
        mp[x]++;
    }

    for (int x = 1; x <= 70; x++) {
        int occ = mp[x];

        if (!occ) {
            for (int i = 0; i < N; i++) dp[x][i] = dp[x - 1][i];
            continue;
        }

        int sq = sqrt(x);
        if (sq * sq == x) {// if perfect square
            int possible = binpow(2ll, occ);
            dp[x][0] = add(dp[x][0], add(-1, possible));

            for (int i = 0; i < N; i++)
                dp[x][i] = add(dp[x][i], mult(possible, dp[x - 1][i]));
            continue;
        }

        int impair = binpow(2ll, occ - 1);// two values possible x or 0 depnding on the parity of choice of the subset
        int pair = binpow(2ll, occ - 1);

        // adding the zeros
        for (int i = 0; i < N; i++) {
            dp[x][i ^ mask[x]] = add(dp[x][i ^ mask[x]], mult(dp[x - 1][i], impair));
        }
        dp[x][mask[x]] = add(dp[x][mask[x]], impair);
        dp[x][0] = add(dp[x][0], add(-1, pair)); // -1 for not considering empty subset

        for (int i = 0; i < N; i++)
            dp[x][i] = add(dp[x][i], mult(pair, dp[x - 1][i]));

    }

    cout << dp[70][0] << endl;

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