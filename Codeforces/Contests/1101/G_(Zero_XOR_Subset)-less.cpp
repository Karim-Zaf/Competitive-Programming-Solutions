/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include<bits/stdc++.h>
typedef long long ll;
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int N = 5e5 + 1, mod = 1e9 + 7, LG = 30;

void insertVector(vector<int>& basis, int mask){
    for (int j = LG - 1; j >= 0; j--){
        if ((mask & (1 << j)) == 0) continue;
        if (!basis[j]){
            basis[j] = mask;
            return;
        }
        mask ^= basis[j];
    }
}

void Solve(){
    int n;
    cin >> n;
    vector<int> v(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];

    vector<vector<int>> dp;

    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ v[i];
    if (pref[n] == 0) return void(cout << "-1\n");

    vector<int> base(LG);
    insertVector(base, pref[n]);

    /*
     * the intuition is that when tha base is full
     * we actually could create any number in the prefix array
     * and so that will make as a zero
     */

    for (int j = n - 1; j >= 1; j--){
        /*
         * if it adds a new bit to the base
         * otherwise we could create it with the current base
         * and so we don't take it cause it would make us a zero
         */
        insertVector(base, pref[j]);
    }

    int ans = 0;
    for (int j = 0; j < LG; j++)ans += (base[j] != 0);

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}
