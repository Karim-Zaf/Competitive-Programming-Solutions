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


void Solve() {
    int n ;
    cin >> n ;
    string s , nw ="";
    cin >> s;

    vector <string> v ;

    for (int i= 0; i<n ;i++){
        if (i&& (s[i-1]=='b'||s[i-1]=='c'||s[i-1]=='d') &&  (s[i]=='b'||s[i]=='c'||s[i]=='d')) {
            v.pb(nw);
            nw = "" ;
        }
        nw += s[i] ;
    }
    v.pb(nw);
    int cnt = 0 ;
    for (auto xs : v ){
        for (int i= 0 ; i<xs.size() ; i++){
            cout << xs[i] ;
            if ((i&& (xs[i-1]=='b'||xs[i-1]=='c'||xs[i-1]=='d') &&  (xs[i]=='a'||xs[i]=='e'))&& i<xs.size()-2)
                cout <<'.' ;
        }
        if (++cnt <v.size())
                cout <<'.' ;

    }

    cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}