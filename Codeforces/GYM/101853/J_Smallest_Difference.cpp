#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}


void solve() {
    int N;
    cin >> N;
    vector<int> a(N), cnt(1e4 + 5);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= 1e4 ; ++i) {
        int curr = cnt[i] + max(cnt[i - 1], cnt[i + 1]);
        ans = max(ans, curr);
    }
    cout<< ans <<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}