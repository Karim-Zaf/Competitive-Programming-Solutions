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

const int N = 1e7 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

vector <long long> sv(N) ;

void sieve(){
    for  (int i =1 ; i<N ; i++)
        for ( int j=i+i ; j<N ; j+=i)
            sv[j]=i;
}

void Solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n),b(n);
    for (auto &x: a)cin >> x;
    for (auto &x: b)cin >> x;
    for (int i= 0 ;i<n ;i++){
        while(a[i]!=b[i]){
            if (a[i]>b[i]){
                a[i]=sv[a[i]];
            }else{
                b[i]=sv[b[i]];
            }
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    sieve();
    cin >> Test_case;
    while (Test_case--) Solve();
}
