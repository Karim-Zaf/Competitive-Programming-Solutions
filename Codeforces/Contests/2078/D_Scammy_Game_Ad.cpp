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
#define arr array<int,4>
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n, l = 1, r = 1;
    cin >> n;

    vector<array<ll, 4>> v(n);
    for (int i = 0; i < n; i++){
        char a, b;
        cin >> a >> v[i][1] >> b >> v[i][3];
        v[i][0] = (a == 'x' ? 1 : 0);
        v[i][2] = (b == 'x' ? 1 : 0);
    }

    int add = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == arr({1, 3, 1, 3})){ add = 2 * (l + r) + 3*add; }
        else if (v[i] == arr({1, 3, 1, 2})){
            l += add;
            add = 2 * l + 1 * r;
        }
        else if (v[i] == arr({1, 2, 1, 3})){
            r += add;
            add = l + 2 * r;
        }
        else if (v[i] == arr({1, 2, 1, 2})){ add = (l + r + 2*add); }
        else if (v[i][0]){
            l += add;
            add = (v[i][1] - 1) * l;
        }
        else if (v[i][2]){
            r += add;
            add = (v[i][3] - 1) * r;
        }

        if (!v[i][0])add += v[i][1];
        if (!v[i][2])add += v[i][3];
    }
    cout << l + r + add << endl;
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
