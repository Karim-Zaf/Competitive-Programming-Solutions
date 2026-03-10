/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define int ll
#define ld long double
const ll N =1e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve() {
    string s ;
    cin >> s ;
    vector <string> vec;
    vec.pb(s);
    while (vec.size() < s.size()){
        vector <string> nw ;
        for (int i= 0 ;i<vec.size() ; i++) {
            reverse(all(vec[i]));
            int len = vec[i].size()/2 ;
            nw.pb(vec[i].substr(0,len));
            nw.pb(vec[i].substr(len,len));
        }
        vec =nw;
    }
    for (auto x: vec ) cout << x ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}