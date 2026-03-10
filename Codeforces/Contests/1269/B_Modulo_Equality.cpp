/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n ,m;
    cin>>n >> m;
    vector <int> a(n) , b(n), poss ;
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x ;
    sort (rall(a));
    sort (rall(b));
    for (int i =0 ; i<n ; i++){
        int nw ;
        if (a[i] >= b[0]) poss.pb(b[0]+m -a[i]);
        else poss.pb(b[0] -a[i]);
    }
    //for (auto x :  poss) cout << x << " "; cout << endl;
    poss.pb(0);
    sort (all(poss));
    for (auto x: poss){
        vector <int> curr =a ;
        for (auto &nww: curr){
            nww += x;
            nww%= m ;
        }
        sort (rall(curr));
        int ok = 1 ;
        for (int i= 0 ; i<n; i++){
            if (curr[i]!=b[i]) ok = 0;
        }
        if (ok ){cout  << x<<endl; return;}
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
