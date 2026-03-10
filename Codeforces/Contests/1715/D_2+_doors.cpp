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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve(){
    int n , m ;
    cin >> n>> m;
    vector <int> res(n+1),zeros(n+1);
    if (m==0){for (int i= 1; i<=n ; i++) cout << res[i] << " " ; cout << endl;return;}
    vector<array<int,3>> st (m);
    vector<array<int,3>> queries[33];
    auto bit =[] (int x , int i_bit){
        return ((1ll<<i_bit)&x)!=0;
    };
    for (int i= 0 ;i<m ; i++){
        array<int,3> a;
        cin >> a[0] >> a[1] >> a[2] ;
        st[i]=a;
        for (int j= 0 ;j <=30; j++){
            if (!bit(a[2],j)) {
                zeros[a[0]]|= (1ll<<j);
                zeros[a[1]]|= (1ll<<j);
            }
        }
    }
    for (int i= 0 ;i<m ;i++){
        array <int,3> a = st[i];
        for (int j= 0 ;j <=30; j++){
            if (bit(a[2],j)&& bit(zeros[a[0]],j))
                res[a[1]]|= (1ll<<j);
            if (bit(a[2],j)&& bit(zeros[a[1]],j))
                res[a[0]]|= (1ll<<j);
        }
    }
    for (int i= 0 ;i<m ;i++) {
        array <int,3> a = st[i];
        if (a[0]<a[1])swap (a[0],a[1]);
        for (int j = 0; j<=30; j++) {
            if (bit(a[2],j)&&!bit(res[a[1]],j) &&!bit(res[a[0]],j)){
                queries[j].pb(a);
            }
        }
    }
    for (int j = 0; j<=30; j++) sort(all(queries[j]));
    for (int k = 0; k<=30; k++) {
        for (auto [i,j,x]: queries[k]){
            if (bit(res[i],k)||bit(res[j],k))continue;
            else res[i]|= (1ll<<k);
        }
    }
    for (int i= 1; i<=n ; i++) cout << res[i] << " " ; cout << endl;



}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}