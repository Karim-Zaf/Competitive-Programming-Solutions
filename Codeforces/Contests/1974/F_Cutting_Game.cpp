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

void Solve() {
    int a, b , n , m , one = 1 , two = 1;
    cin >> a >> b >> n >> m ;

    int ans[2]={0,0};

    multiset <pair<int,int>> xx, yy ;

    vector<pair<int,int>>vp(n) ;
    for (auto &x: vp )cin >> x.F >> x.S ;
    for (auto x: vp )xx.insert({x.F,x.S});
    for (auto x: vp )yy.insert({x.S,x.F});

    for (int i= 0 , k; i<m  ; i++){
        char c ;
        cin >> c >> k ;

        int cnt= 0 ;
        if (c=='D'){
            a -= k ;

            auto it = xx.lower_bound({a , INF}) ;

            vector<pair<int,int>> er ;
            while (it != xx.end()){
                er.pb (*it) ;
                cnt ++ ;
                it ++ ;
            }

            for (auto x: er ){
                xx.erase(x) ;
                yy.erase({x.S, x.F}) ;
            }
        }
        if (c=='U'){


            one += k ;
            auto it = xx.lower_bound({one , -INF}) ;
            auto it2 = xx.begin() ;
            vector<pair<int,int>> er ;
            while (it2 != it ){
                er.pb (*it2) ;
                cnt ++ ;
                it2 ++ ;
            }

            for (auto x: er ){
                xx.erase(x) ;
                yy.erase({x.S, x.F}) ;
            }
        }
        if (c=='R'){

            b -= k ;
            auto it = yy.lower_bound({b , INF}) ;
            vector<pair<int,int>> er ;
            while (it != yy.end()){
                er.pb (*it) ;
                cnt ++ ;
                it ++ ;
            }

            for (auto x: er ){
                yy.erase(x) ;
                xx.erase({x.S, x.F}) ;
            }
        }
        if (c=='L'){
            two += k ;
            auto it = yy.lower_bound({two , -INF}) ;
            auto it2 = yy.begin() ;
            vector<pair<int,int>> er ;

            while (it2 != it){
                er.pb (*it2) ;
                cnt ++ ;
                it2 ++ ;
            }

            for (auto x: er ){
                yy.erase(x) ;
                xx.erase({x.S, x.F}) ;
            }
        }


        ans[i%2]+= cnt  ;
    }
    cout << ans[0] << " " << ans[1] << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}