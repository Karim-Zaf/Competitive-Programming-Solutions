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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

vector<int> divisors[N];

void Solve() {
    int n , ans =0;
    cin >> n ;
    vector<int> v(n) ;
    for (int i= 0; i<n ; i++) cin >> v[i] ;
    for (auto d : divisors[n]){
        int g = 0;
        for (int x = 0 ; x < d; x++){
            for (int curr =x ;curr<n ; curr += d){
                g = __gcd (g,abs(v[curr]-v[x]));
            }
        }
        ans += (g!=1);
    }
    cout << ans << endl;
}

void preprocess(){

    for (int i= 1; i<N ; i++){
        for (int j=i ; j<N ; j+=i )
            divisors[j].pb(i);
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    preprocess();
    while (Test_case--) Solve();
}