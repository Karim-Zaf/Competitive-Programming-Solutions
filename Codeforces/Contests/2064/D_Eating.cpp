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

const int LG = 31;
int ind[LG][N];

void Solve(){
    int n, q;
    cin >> n >> q;
    for (int j = 0; j < LG; j++)ind[0][j] = 0;
    vector<int> v(n + 1), suff(n + 6);
    for (int i = 1; i <= n; i++)cin >> v[i];

    for (int i = n; i >= 1; i--) suff[i] = suff[i + 1] ^ v[i];
    for (int i = 1; i <= n + 1; i++){
        for (int j = 0; j < LG; j++)
            ind[j][i] = ind[j][i - 1];

        for (int j = LG - 2; j >= 0; j--){
            if ((1 << j) & v[i - 1])
                ind[j][i] = i;
            ind[j][i] = max(ind[j][i], ind[j + 1][i]);
        }
    }

    auto f = [&](int x){
        int indx = -1;
        for (int j = 0; j < LG; j++)
            if ((1 << j) & x)indx = j;
        return indx;
    };
    while (q--){
        int x;
        cin >> x;

        int curr = ind[f(x)][n + 1];
        while (x && curr >= 1){
            if ((x ^ suff[curr]) >= v[curr - 1]){
                if ((x ^ suff[curr - 1]) == 0){
                    curr--;
                    break;
                }

                curr = ind[f(x ^ suff[curr - 1])][curr - 1];
            }
            else break;
        }

        cout << min(n, n - curr + 1) << " ";
    }
    cout << endl;
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
