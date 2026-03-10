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

const int  N=1e6 + 5 ,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int Trie [N][26] , mp[N] , nxt = 0 ;

void build (string &s){
    int curr = 0 ;
    for (auto c: s){
        if (!Trie[curr][c-'a']) Trie[curr][c-'a']= ++nxt ;
        mp[Trie[curr][c-'a']]++;
        curr = Trie[curr][c-'a'];
    }
}

int work (string &s){
    int curr = 0, ret = 0;
    for (auto c: s){
        if (!Trie[curr][c-'a']) return ret ;
        ret += mp[Trie[curr][c-'a']];
        curr = Trie[curr][c-'a'];
    }
    return ret ;
}

void Solve() {
    int n , ans = 0, all = 0;
    cin >> n ;
    vector <string> v(n);
    for (auto &x: v) {
        cin >> x;
        build (x);
        reverse(all(x));
        all += x.size() ;
    }
    for (auto x: v)  ans += work (x);

    cout << 2*n*all -2*ans << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}