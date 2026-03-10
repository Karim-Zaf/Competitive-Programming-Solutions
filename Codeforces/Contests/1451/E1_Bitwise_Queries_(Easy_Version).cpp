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

int ask (string s , int i , int j) {
    int x ;
    cout << s << " " << i << " " << j << endl ;
    cout.flush() ;
    cin >> x;
    return x ;
}

void Solve() {
    int n , first, one , two , three ;
    cin >> n ;
    vector<int> v(n+1) ;
    for (int i= 2 ; i<=n ; i++)v[i]= ask ("XOR",1,i);
    one = ask ("AND",1,2)*2+v[2];
    two = ask ("AND",1,3)*2+v[3];
    three = ask ("AND",2,3)*2+ (v[3]^v[2]);
    first = (one + two - three)/2;
    cout << "! "<< first <<" ";
    for (int i= 2; i<=n ; i++) cout << (first^v[i]) << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}