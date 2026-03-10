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

const int  N=2e5+30,MOD=1e9+7,mod=998244353,INF=1e18+10;

void Solve() {
    int b , n , three=INF;
    cin >> b >> n ;

    vector<int> cycle , vis(n);
    cycle.pb(1);
    vis[1]=1;
    while (true){
        int x = cycle.back()*b%n;
        if (vis[x]) break ;
        if (x==0){
            cout <<"1 " <<  cycle.size() << endl;
            return ;
        }
        cycle.pb(x);
        if (cycle.size()>= n +5){cout << 0 << endl; return ;}
    }
    int sz = cycle.size();
    int two = sz;
    bool flag = true;

    if (sz%2) flag = false ;
    for (int i= 0 ; i< sz/2 ;i++){
        int curr = cycle[i],opp=cycle[i+ sz/2];
        curr = n-curr;
        if (curr != opp)flag = false ;
    }
    if (flag) three= sz/2 ;

    if (two <= three){
        cout << "2 " << two << endl;
    }else {
        cout << "3 " << three << endl;
    }



}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}