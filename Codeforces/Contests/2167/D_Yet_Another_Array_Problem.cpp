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

const int N = 200 , mod = 1e9 + 7, INF = 1e18 + 10;

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

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int g = 0;
    for (auto x : v) g = __gcd(g, x);
    for (auto x : primes){ if (__gcd(g, x) == 1) return void(cout << x << "\n"); }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    sieve();
    while (Test_case--) Solve();
}
