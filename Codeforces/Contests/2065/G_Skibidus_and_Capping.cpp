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

vector<int> factors(int n){
    vector<int> res;
    for (int d = 2; d * d <= n; d++){
        if (n % d) continue;
        while (n % d == 0){
            res.push_back(d);
            n /= d;
        }
    }
    if (n > 1)res.push_back(n);
    return res;
}

void Solve(){
    int n, ans = 0;
    cin >> n;

    int ind = 0;
    map<int,int> exact, two_prime;
    vector<int> v(n);

    for (auto& x : v) cin >> x;
    for (auto x : v){
        vector<int> curr = factors(x);
        if (curr.size() > 2) continue;
        // traitement;

        exact[x]++;
        if (curr.size() == 2){
            two_prime[curr.front()]++;
            two_prime[curr.back()]++;
            if (curr.back() == curr.front()){ two_prime[curr.front()]--; }
        }
        ind += (curr.size() == 1);

        if (curr.size() == 2){
            if (curr.front() == curr.back()){
                ans += exact[x];
                ans += exact[curr.front()];
            }
            else{
                ans += exact[curr.back()];
                ans += exact[curr.front()];
                ans += exact[x];
            }
        }
        else{
            ans += (ind - exact[x]);
            ans += two_prime[x];
        }
    }
    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;

    while (Test_case--) Solve();
}
