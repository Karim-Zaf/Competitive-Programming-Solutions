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

int binpow(int a, int k, int res =1,int Mod=mod){
    while (k){if(k%2)res=(res*a)%Mod;a=(a*a)%Mod;k/=2;}return res;
}
int modinv(int a,int Mod=mod){return binpow(a,Mod-2);}
int mult(int a, int b,int Mod=mod){b%=Mod;return a%Mod*b%Mod;}
int add (int a, int b,int Mod=mod){ return ((a%Mod+b%Mod)%Mod+Mod)%Mod;}
int divide(int a, int b,int Mod=mod){a%=Mod;b=modinv(b)%Mod;return (a*b)%Mod;}


void Solve() {
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n+1) ,pref(n+1);

    for (int i= 1; i<=n ;i++){
        cin >> v[i] ;
        pref[i]= pref[i-1]+ v[i] ;
    }

    int mn = 0 , mx = 0 ;
    for (int i =1; i<=n ;i++){

        mx = max (mx, pref[i]-mn) ;
        mn = min (mn, pref[i]);
    }

    int ans= accumulate(all(v),0ll) ;
    ans= add(ans,mult (mx,add(-1,binpow(2,k))))     ;
    kar (mx);
    kar (add(-1,binpow(mx,k)))
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}