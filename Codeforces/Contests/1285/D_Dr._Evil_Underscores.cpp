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

const int  N=2e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int group[N] , x[N] , cnt [N], eksem[N], mp[N], oldx[N];

void Solve() {
    int n , mn = INF, nw = 1 ;
    cin>> n ;
    vector<int> v(n) ;
    for (auto &e: v) cin >> e;


    for (int i= 31 ; i>=0 ; i--){
        for (int j = 0 ; j<n ;j++){
            cnt[group[j]]+= (((1ll<<i) &v[j])!=0) ;
            mp[group[j]]++ ;
        }

        for (int g=0 ;g<=5*n; g++) if (cnt[g]!=mp[g]&&cnt[g]) {
            eksem[g] = nw ;
            nw+=2 ;
        }
        for (int j = 0 ; j<n ;j++){
            cnt[group[j]]-= (((1ll<<i) &v[j])!=0) ;
            mp[group[j]]-- ;
        }

        for (int j = 0 ;j<n ;j++){
            int bit = (((1ll<<i)&v[j])!=0);
            if (eksem[group[j]]){
                x[eksem[group[j]]+bit]=oldx[group[j]] ;
                group[j]= eksem[group[j]]+ bit ;
                if (bit==0) x[group[j]]|=(1ll<<i) ;
            }else if (bit) {
                x[group[j]]|=(1ll<<i);
            }
        }
        for (int j= 0 ; j<=5*n; j++) {
            oldx[j]= x[j] ;
            eksem[j]=0 ;
        }
    }
    for(int i= 0 ; i<n ;i++) mn = min (mn , v[i]^x[group[i]]) ;
    cout << mn << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
