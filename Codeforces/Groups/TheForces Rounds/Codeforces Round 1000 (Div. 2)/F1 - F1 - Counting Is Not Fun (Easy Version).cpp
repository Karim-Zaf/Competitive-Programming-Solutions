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

const int N = 3e5 + 30, mod = 998244353, INF = 1e18 + 10;

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

int fact[N]{1}, invfact[N]{1};
void factorial(){ for (int i = 1; i < N; i++)fact[i] = mult(i, fact[i - 1]); }

void inverses(){
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 1; i >= 1; i--)invfact[i - 1] = mult(invfact[i], i);
}

int C(int n, int k){
    if (n < k)return 0;
    return divide(fact[n], mult(fact[n - k], fact[k]));
}

int cat[N];

int starsandbars(int n,int k){ return C(n + k - 1, n); }
int catalan(int n){ return mult(divide(1, n + 1), C(2 * n, n)); } // there is another method in O(n)

void Solve(){
    int n;
    cin >> n;
    string s = "";

    cout << catalan(n) << " ";
    vector<int> mp(2 * n + 5);
    mp[0] = 1, mp[2 * n + 1] = -1;

    for (int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        mp[l] = 1;
        mp[r] = -1;
        set<int> curr;

        int ans = 1;
        vector<int> lst;
        for (int i = 0; i <= 2 * n + 1; i++){
            lst.push_back(i);
            if (mp[i] == -1){
                int cnt = 0;
                while (mp[lst.back()] != 1){
                    cnt++;
                    lst.pop_back();
                }
                lst.pop_back();

                ans = mult(ans, cat[cnt / 2]);
            }
        }
        cout << ans << " ";
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

    factorial();
    inverses();
    for (int i = 0; i < N; i++) cat[i] = catalan(i);
    while (Test_case--) Solve();
}
