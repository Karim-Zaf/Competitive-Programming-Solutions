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

char ask (int a , int b , int c, int d ){
    char ret ;
    cout << "? " <<a << " " << b << " " << c<< " " << d << endl;
    cout.flush();
    cin >> ret;
    return ret;
}

void Solve() {
    int n ;
    cin >> n ;

    // find max
    int mx = 0 , oth = 0;
    for (int i= 1 ; i<n ;i++){
        char x = ask (mx,mx,i,i) ;
        if (x=='<')mx = i;
    }

    // finding best one ;
    set<int> indxes ;
    indxes.insert(0) ;
    for (int i= 1; i<n ;i++){
        char x = ask (mx,oth,mx,i);
        if (x=='<'){
            oth = i ;
            indxes.clear();
            indxes.insert(i);
        }
        else if (x=='='){
            indxes.insert(i);
        }
    }
    int mn = *indxes.begin() ;
    for (auto xx: indxes){
        char x = ask (mn,mn,xx,xx) ;
        if (x=='>')mn = xx;
    }


    cout << "! " << mx << " " << mn << endl;
    cout .flush();
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}