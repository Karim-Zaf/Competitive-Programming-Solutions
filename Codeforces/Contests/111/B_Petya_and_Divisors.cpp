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
#define endl '\n'
#define int ll

const long long N=1e5+8,MOD=1e9+7,mod=1e12+7,INF=1e18;

vector <int> divisors[N] , lst(N);

void Solve(){
    int q,x,y;
    cin >> q ;
    for (int i=1 ;i<N;i++)
        for (int j= i ;j<N;j+=i)
            divisors[j].pb(i);

    for (int i= 1;i<=q ;i++){
        cin >> x >> y ;
        int cnt = 0;
        for (auto divi : divisors[x]) {
            cnt += (lst[divi] < i - y);
            lst[divi]=i;
        }
        cout << cnt << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}