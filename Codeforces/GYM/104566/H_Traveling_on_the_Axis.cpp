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

const int N=1e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

string s ;
int dp[N][2] ;

int work (int pos , int indx ){
    if (pos >= s.size()) return 0 ;
    int & ret = dp[pos][indx] ;
    if (ret != -1 ) return ret ;
    int curr = s[pos]-'0';
    curr^=indx ;
    ret = s.size()-pos;
    if (curr ==0) ret *= 2;
    else indx^=1 ;
    ret += work(pos+1,indx);
    return ret ;
}

void Solve() {
    cin >> s ;
    for (int i= 0; i<=s.size()+10 ;i++)dp[i][0]=dp[i][1]=-1;
    int ans = 0 ;
    for (int i= 0; i<s.size() ; i++) ans +=work (i,0) ;
    cout << ans<<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}