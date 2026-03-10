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

int dp[20][5][2];
string s ;

int work (int pos, int nb, int flag ){
    if (nb>3)return 0 ;
    if (pos>=s.size()&&nb<=3) return 1;
    if (pos>=s.size()) return 0;
    int& ret= dp[pos][nb][flag] ;
    if (ret!=-1) return ret ;
    if (s[pos]=='0') ret = work(pos+1,nb,flag);
    else ret = work(pos+1,nb,true);

    if (flag){
        ret += 9ll*work(pos+1,nb+1,flag) ;
    }else if (s[pos]!='0') {
        ret += work(pos+1,nb+1,false);
        ret += (s[pos]-'0'-1ll)*work (pos+1,nb+1,true);
    }
    return ret ;
}

void Solve() {
    int a ,b , cnta = 0 , cntb= 0;
    cin >> a >> b ;
    memset(dp,-1 ,sizeof(dp));
    s= to_string(a-1);
    cnta = work(0,0,0);
    memset(dp,-1 ,sizeof(dp));
    s= to_string(b);
    cntb = work(0,0,0);
    cout << cntb-cnta << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}