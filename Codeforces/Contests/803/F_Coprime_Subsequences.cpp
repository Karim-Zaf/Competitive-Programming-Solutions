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

int mp[N], dp[N];

int binpow(int a, int k, int res =1,int Mod=mod){
    while (k){if(k%2)res=(res*a)%Mod;a=(a*a)%Mod;k/=2;}return res;
}
int modinv(int a,int Mod=mod){return binpow(a,Mod-2);}
int mult(int a, int b,int Mod=mod){b%=Mod;return a%Mod*b%Mod;}
int add (int a, int b,int Mod=mod){ return ((a%Mod+b%Mod)%Mod+Mod)%Mod;}
int divide(int a, int b,int Mod=mod){a%=Mod;b=modinv(b)%Mod;return (a*b)%Mod;}


vector<int> fact(int x) {
    vector<int> primes;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            primes.pb(i);
        }
    }
    if (x > 1) primes.pb(x);
    return primes;
}

void Solve() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;

    for (auto x: v) {

        for (int i= 1; i*i <= x ; i++){
            if (x%i) continue;
            mp[i]++ ;
            if (x/i==i) continue;
            mp[x/i]++ ;
        }
    }


    auto arith = [](int x){
        return add(-1,binpow(2ll,x)) ;
    };
    for (int i= N-1 ; i>=1 ; i--){
        dp[i]= arith(mp[i]) ;
        for (int j=i+i ; j<N; j+=i )
            dp[i]= add(dp[i],-dp[j]);
    }
    cout << dp[1] << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}