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
#define endl '\n'
#define int long long

const long long N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

void Solve() {
    string s ;
    cin >> s ;
    int size=0 , asc =0 ;
    set <int> desc ;
    for (auto c : s){
        if (c=='+') {
            size++ ;
        }
        if (c=='-'){
            if (desc.size()>=1 && *prev(desc.end())==size)desc .erase(*prev(desc.end())) ;
            if (asc==size) asc--;
            size-- ;
        }
        if (c=='1'){
            if (desc.size()>=1){cout << "NO" << endl; return;}
            asc = size ;
        }
        if (c=='0'){
            if (asc==size||size<=1) {cout << "NO"<< endl;return;}
            desc.insert( size);
        }
    }
    cout << "YES\n";

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}