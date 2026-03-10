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

const int  N=5e6+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

map <int,int> mp, mp2 ;

int factors(int n){
    for(int i = 2; i *i <= n;i++){
        if(n%i) continue;
        while(n % i == 0){
            n /= i;
            mp[i]++;
        }
    }
    if(n > 1)mp[n]++;
    int res = 1;
    for (auto x: mp) res*=(x.S+1);

    return res;
}
int factors2(int n){
    for(int i = 2; i *i <= n;i++){
        if(n%i) continue;
        while(n % i == 0){
            n /= i;
            mp2[i]++;
        }
    }
    if(n > 1)mp2[n]++;
    int res = 1;
    for (auto x: mp2) res*=(x.S+1);

    return res;
}

void Solve(){
    int n  , q ;
    cin >> n >> q ;
    mp.clear();
    factors (n) ;
    while (q--){
        int x;cin >> x;
        if (x==2) {
            mp.clear();
            factors (n) ;
        }else{
            cin >> x ;
            int cnt = factors(x) ;
            mp2.clear();
            int ok =1 ;
            factors2 (cnt) ;
            for (auto x: mp2){
                if (mp[x.F]<x.S) ok = 0 ;
            }
            if (ok)cout << "YES\n";
            else cout << "NO\n" ;
        }
    }
    cout<< endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while(Test_case--)Solve();
}