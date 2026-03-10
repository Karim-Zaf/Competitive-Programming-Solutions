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
 
const int N = 5e6 + 30, mod = 1e9 + 7, INF = 1e18 + 10;
 
const int LG = 35;
int Trie[N][2], nxt = 0;
int mp[N];
int n, k;
 
int val_bit(int x, int bit){ return (((1ll << bit) & x) != 0); }
 
void build(int mask, int indx){
    int curr = 0;
    for (int bit = LG - 1; bit >= 0; bit--){
        int curr_bit = val_bit(mask, bit);
        if (!Trie[curr][curr_bit]) Trie[curr][curr_bit] = ++nxt;
        mp[Trie[curr][curr_bit]] = indx;
        curr = Trie[curr][curr_bit];
    }
}
 
int work(int mask, int indx){
    int curr = 0, ret = INF;
    for (int bit = LG - 1; bit >= 0; bit--){
        if (val_bit(k, bit) == 0){
            int pot_bit = 1 ^ val_bit(mask, bit);
            if (mp[Trie[curr][pot_bit]] != -1)ret = min(ret, indx - mp[Trie[curr][pot_bit]]);
        }
 
        int curr_bit = val_bit(mask, bit) ^ val_bit(k, bit);
 
        if (!Trie[curr][curr_bit]) return ret;
        curr = Trie[curr][curr_bit];
    }
    if (mp[curr] != -1) ret = min(ret, indx - mp[curr]);
    return ret;
}
 
void Solve(){
    int ans = INF;
    cin >> n >> k;
    vector<int> v(n + 1);
 
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        build(v[i], i);
        ans = min(ans, work(v[i], i));
    }
 
    for (int j = 0; j <= nxt + 4; j++){
        mp[j] = -1;
        for (int i = 0; i < 2; i++)
            Trie[j][i] = 0;
    }
    nxt = 0;
 
    reverse(v.begin() +1 , v.end());
 
    for (int i = 1; i <= n; i++){
        build(v[i], i);
        ans = min(ans, work(v[i], i));
    }
 
    for (int j = 0; j <= nxt + 4; j++){
        mp[j] = -1;
        for (int i = 0; i < 2; i++)
            Trie[j][i] = 0;
    }
    nxt = 0;
    cout << (ans == INF ? -1 : ans + 1) << endl;
}
 
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    for (int i = 0; i < N; i++) mp[i] = -1;
    while (Test_case--) Solve();
}