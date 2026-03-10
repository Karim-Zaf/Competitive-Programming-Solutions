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

void Solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& x : v) cin >> x;

    map<int,int> one, two;
    one[v[0]]++;
    one[v[1]]++;
    for (int i = 2; i < n; i++) two[v[i]]++;

    if (one[0] && two[0]){
        cout << 3 << endl;
        cout << "1 2\n2 " << n-1 << endl;
        cout << "1 2\n";
        return;
    }
    if (!one[0] && !two[0])return void(cout << "1\n1 " << n << endl);
    cout << 2 << endl;

    if (!one[0]){
        cout << 3 << " " << n << endl;
        cout << "1 3" << endl;
        return;
    }

    cout << "1 2" << endl;
    cout << "1 " << n - 1 << endl;
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
