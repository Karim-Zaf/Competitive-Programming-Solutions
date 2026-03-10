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

void Solve() {
    int n, k , m ;
    string s , oth="";
    cin >> n >> k >> m >> s ;
    int flag =0 , cnt = 0;
    for (auto c : s){
        int curr = c-'a';
        flag|=(1ll<<curr);
        if (flag == (1ll<<k) -1){
            oth+= c ;
            flag = 0 ;
            cnt ++ ;
        }
    }

    if (cnt>=n){cout << "Yes\n";}
    else {
        cout <<"NO\n";
        while(oth.size()<n){
            for (int i= 0; i<k; i++){
                if (!((1ll<<i)&flag)){
                    oth+= char(i+'a');
                    break;
                }
            }
        }
        cout << oth << endl;
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