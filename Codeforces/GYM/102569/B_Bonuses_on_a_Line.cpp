/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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

const ll N =1e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve() {
    int n , x , res= 0 ;
    cin >> n >> x;
    vector <int> v(n) ;
    for (int i= 0 ;i<n ;i++) cin >> v[i];
    for (int i= 0 ;i<n ;i++) {
        if (v[i]<=0) {
            if (abs(v[i])> x) continue;
            int pos = upper_bound (all(v),0) -v.begin();
            int nb = pos -i;
            int nw_x = x - abs(v[i]);
            pos = upper_bound (all(v),(v[i]+nw_x)) -v.begin();
            int nw = pos -i ;
            nw -=nb ;
            if (nw>=0 ) nb += nw ;
            res =  max (res , nb);

        }else {
            if (v[i]> x) continue;
            int pos = lower_bound (all(v),0) -v.begin();
            int nb = i-pos+1 ;
            int nw_x = x -v[i] ;
            pos = lower_bound (all(v),(v[i]-nw_x)) -v.begin();
            int nw = i- pos+1 ;
            nw -= nb ;
            if (nw>=0) nb += nw ;
            res = max (res , nb) ;
        }
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}