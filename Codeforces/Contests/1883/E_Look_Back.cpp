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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;


void Solve() {

    int n ,res = 0 ;
    cin >> n;
    vector <int> v(n), shift(n) ;
    for (int i= 0 ; i<n ;i++){
        cin >>v[i] ;
        if(!i) continue;
        int curr = (int)log2(v[i]), prev = (int)log2(v[i-1])+shift[i-1];
        int x = v[i];
        if (curr >prev)continue;
        shift[i]=shift[i-1];
        while ((int)log2(x) <(int)log2(v[i-1])){
            x*=2;
            shift[i]++;
        }
        int other = v[i-1] ;

        while ((int)log2(other) <(int)log2(v[i])) {
            other*=2;
            shift[i]--;
        }
        if(x<other)shift[i]++;
        res += shift[i];
    }
    kar (shift);
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}