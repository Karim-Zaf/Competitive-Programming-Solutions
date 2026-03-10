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

const int  N=2e5,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    string s ;
    cin >> s ;
    int n = s.size() ;
    set <int> upper, lower ;
    for (int i= 0 ;i<n ;i++){
        if (s[i]=='b'){
            if (lower.size())
            lower.erase (*prev(lower.end()));
        }else if(s[i]=='B'){
            if (upper.size())
                upper.erase (*prev(upper.end()));
        }else if (s[i]<='z'&& s[i]>='a')lower.insert(i);
        else upper.insert(i);
    }
    for (auto x: upper)lower.insert(x);
    for (auto x: lower) cout << s[x]; cout << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}