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

vector<long long> primes;

void sieve(){
    vector<int> visited(N);
    for (int i = 2; i < N; i++){
        if (visited[i]) continue;
        primes.push_back(i);
        for (int j = i; j < N; j += i)
            visited[j] = 1;
    }
}

vector<int> factors(int n){
    vector<int> res;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++){
        if (n % primes[i]) continue;
        res.push_back(primes[i]);
        while (n % primes[i] == 0){ n /= primes[i]; }
    }
    if (n > 1)res.push_back(n);
    return res;
}

int mp[N];

void Solve(){
    int n;
    cin >> n;

    vector<vector<int>> fact(n);
    vector<int> v(n);
    vector<int> b(n);
    for (auto& x : v) cin >> x;
    for (auto& x : b) cin >> x;

    int ans = 2;
    for (int i = 0; i < n; i++){
        fact[i] = factors(v[i]);
        for (auto& x : fact[i]){
            mp[x]++;
            kar(x);
            if (mp[x] >= 2) ans = 0;
        }
    }

    for (auto i = 0; i < n; i++){
        vector<int> curr = factors(v[i] + 1);
        for (auto& x : curr){
            kar(mp[x])
            if (mp[x]) ans = min(ans, 1ll);
        }
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++){ for (auto& x : fact[i]){ mp[x] = 0; } }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
