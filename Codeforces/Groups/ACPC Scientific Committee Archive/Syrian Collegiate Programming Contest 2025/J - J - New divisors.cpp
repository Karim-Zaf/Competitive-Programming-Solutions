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
 
const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;
 
int binpow(int a, int k, int res = 1,int Mod = mod){
    while (k){
        if (k % 2)res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}
 
int modinv(int a,int Mod = mod){ return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod){
    b %= Mod;
    return a % Mod * b % Mod;
}
 
int add(int a, int b,int Mod = mod){ return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod){
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}
 
int query(char c, int x){
    if (x < 1) return 0;
    int ret;
    cout << "? " << c << " " << x << endl;
    cout.flush();
    cin >> ret;
    return ret;
}
 
void rep(int x){
    cout << "! " << x << endl;
    cout.flush();
}
 
map<int,int> mp;
const int MX = 1e9;
 
void work(){
    mp.clear();
    int sum = 0;
    while (true){
        int l = 1, r = MX, lst = -1;
        int nw_sum = sum;
        while (l <= r){
            int md = l + (r - l) / 2;
            int curr;
 
            if (mp.count(md)) curr = mp[md];
            else curr = mp[md] = query('A', md);
 
            if (curr > sum){
                nw_sum = curr;
                lst = md;
                r = md - 1;
            }
            else l = md + 1;
        }
 
        if (lst == -1)return;
        sum = nw_sum;
    }
}
 
int ans;
map<int,int> mp2;
 
void work2(){
    mp2.clear();
    int prv = 0;
    for (auto [key,val] : mp){
        if (val == prv) continue;
        if (!mp2.count(key))mp2[key] = query('B', key);
        if (!mp2.count(key-1))mp2[key - 1] = query('B', key - 1);
        prv = val;
    }
}
 
void Solve(){
    int a, b;
    cin >> a >> b;
    ans = mult(a, b);
    work();
    work2();
 
    int prv_key = 0, prv = 0;
    for (auto [key, val] : mp){
        if (val == prv) continue;
        int one = add(mp[key] ,- mp[prv_key]);
        int two = add(mp2[key] ,- mp2[key - 1]);
        ans = divide(ans, one + 1);
        ans = divide(ans, two + 1);
        ans = mult(ans, one + two + 1);
        prv_key = key;
        prv = val;
    }
    rep(ans);
}
 
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}