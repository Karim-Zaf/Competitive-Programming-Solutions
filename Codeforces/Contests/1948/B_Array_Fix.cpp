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

bool is_sorted(vector<int> &v){
    int x = v.size() ;
    for (int i= 1; i<x; i++){
        if (v[i]<v[i-1])return false;
    }
    return true;
}

void Solve() {
    int n ;
    cin >> n ;
    vector<int> v(n) , res ;
    for (int i= 0 ; i<n ;i++){
        cin >> v[i] ;
    }
    if (is_sorted(v)){
        cout << "YES\n";
        return;
    }

    for (int i= 0 ; i<n ;i++){
        vector<int> nw , second;
        for (int j = 0 ; j<=i ; j++){
            if (v[j]>=10){
                nw.pb(v[j]/10);
                nw.pb(v[j]%10);
            }
            else nw.pb(v[j]);
        }for (int j= i+1 ; j<n ;j++){
            nw.pb(v[j]);
        }

        if (is_sorted(nw)){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
};

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}