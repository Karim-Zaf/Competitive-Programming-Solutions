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
 
void Solve() {
    map<int, string> mp;
 
    mp[1508] = "pocket watches";
    mp[1608] = "telescopes";
    mp[1708] = "steam engines";
    mp[1808] = "telephones";
    mp[1908] = "airplanes";
    mp[2008] = "terraforming";
    mp[2108] = "exploration";
    mp[2208] = "relaxing";
    mp[2308] = "going above and beyond";
    mp[2408] = "second chances";
    mp[2508] = "the origin";
    mp[2608] = "empowering the youth";
    mp[2708] = "ECPC";
    int n;
    cin >> n;
    cout << mp[n] << endl;
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}