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

int work (int k ){
    int cnt = 0 ;
    while (k%10==0) {
        cnt ++ ;
        k/= 10 ;
    }
    return cnt ;
}

void Solve() {
    int m, n , x= 0 ;
    cin >> n >> m ;
    vector<int> v(n) ;
    multiset<pair<int,int>,greater<>> s ;
    for (auto &xx: v) {
        cin >> xx;
        string ss = to_string(xx);
        s.insert({work(xx),ss.size()});
    }
    while(true){
        if (x==0){
            auto[zeros,sz] = *s.begin();
            s.erase(s.find(*s.begin()));
            s.insert({0,sz -zeros}) ;
        }else{
            if (s.size()==1) break;
            auto[zeros1,sz1] = *s.begin();
            auto[zeros2,sz2] = *s.rbegin();
            s.erase(s.find(*s.begin()));
            s.erase(s.find(*s.rbegin()));
            s.insert({zeros2,sz1+sz2});
        }
        x^=1 ;
    }
    int szz = s.begin()->S;
    cout << (szz<=m ?"Anna" : "Sasha") << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}