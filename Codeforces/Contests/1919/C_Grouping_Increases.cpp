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

void Solve() {
    vector<int> one, two ;
    int res = 0 , n  ;
    cin >> n ;
    for (int i=0; i<n; i++){
        int indx = 1 ,x ; cin >> x;
        if (one.empty()) indx =1 ;
        else if (x>one.back()&&two.empty())indx = 2;
        else if (x<=one.back() && two.empty()) indx = 1 ;
        else if (x>one.back() && x> two.back()){
            if (one.back() < two.back())indx =1 ;
            else indx =2 ;
        }else if (x<=one.back() && x<= two.back()){
            if (one.back() <two.back())indx = 1 ;
            else indx = 2 ;
        }else if (x<=one.back()){
            indx = 1;
        }else indx = 2 ;
        if (indx==1 ){
            if (!one.empty()) res += (x>one.back());
            one.pb(x);
        }else {
            if (!two.empty()) res += (x>two.back());
            two.pb(x);
        }
    }
    kar (one) ;
    kar (two);
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