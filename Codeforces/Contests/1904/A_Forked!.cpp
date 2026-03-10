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

const int  N=2e5+40 ,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve() {
    int one , two , kone ,ktwo , qone , qtwo , a = 0 , b = 0, nwa , nwb ,res = 0;
    cin >> a >> b >> kone>> ktwo >> qone >> qtwo ;
    ll dx[]={b,a,b,-a,-b,a,-a,-b} ;
    ll dy[]={a,b,-a,b,a,-b,-b,-a} ;
    set <pair <int,int>> s ;
    for (int i= 0 ; i<8 ; i++){
        int x = kone + dx[i];
        int y = ktwo + dy[i];
        for (int j= 0 ; j<8 ; j++){
            int nwx = x + dx[j] ;
            int nwy = y + dy[j] ;
            if (nwx ==qone && nwy == qtwo ) {
                res++;
                s.insert ({x,y});
            }
        }
    }
    cout << s.size() << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}