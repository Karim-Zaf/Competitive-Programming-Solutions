/*Karim_ZAF*/
 
#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'
 
const int LG = 30;
 
void Solve(){
    int n;
    cin >> n;
    vector<int> v(n);
 
    set<int> s;
 
    for (auto& x : v) cin >> x;
 
    sort(all(v));
 
    auto get =[&](int x, vector<int> &v){
        return upper_bound(all(v),x) - lower_bound(all(v),x);
    };
 
    int ans = 0;
    for (int j = LG - 1; j >= 0; j--){
        vector<int> nw_v;
        for (auto &x : v) s.insert((x >> (j + 1)) << (j + 1));
        for (auto &x : v) nw_v.pb(((x >> (j)) << (j)));
 
        int cnt = 0;
        for (auto &val : s){ cnt += get(val,nw_v) * get(val + (1 << j),nw_v); }
        ans += cnt * j;
 
        s.clear();
    }
 
    cout << ans << endl;
}
 
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}