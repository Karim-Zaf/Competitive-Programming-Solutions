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

const int  N=1e5+8,MOD=1e9+7,mod=1e9+7,INF=1e17;


void Solve() {
    int n , res =0;
    cin >> n ;
    vector <int> a(n), b(n);
    vector <array <vector <int> ,2>> ans ;
    vector <array<vector <int>,2>> nw_ans ;
    array <vector <int>,2> v ;
    for (int i= 0 ;i<n;i++) {
        v[0].pb(i);
        v[1].pb(i);
        cin >> a[i];
    }
    for (auto &x:b) cin >> x;
    ans.pb(v);
    for (int i= 29; i>=0; i--){
        bool flag = true ;
        nw_ans.clear();
        for (auto vect: ans ){
            int nb_zero = 0 , nb2_one = 0 ;
            array <vector <int>,2> one , two ;
            for (auto index: vect[0]){
                if (!((1ll<<i) &a[index])) {
                    nb_zero++ ;
                    one[0].pb(index);
                }else two[0].pb(index) ;
            }
            for (auto index : vect[1]){
                if ((1ll<<i) &b[index]) {
                    nb2_one++;
                    one[1].pb(index);
                }else two[1].pb(index) ;
            }
            if(!one[0].empty())nw_ans.pb(one);
            if(!two[0].empty())nw_ans.pb(two) ;
            if (nb_zero!=nb2_one) {
                flag = false ;
                break;
            }
        }
        if (flag){
            ans = nw_ans ;
            res +=(1ll<<i);
        }
    }
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