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
#define dbg(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'
 
const int N=3e6+30,mod=1e9+7,MOD=mod,INF=7e17+10;
 
int dp[20][2][2] ;
string s;
int n , k ;
 
 
int work (int pos , bool flag, bool flagzero){
    if (pos== s.size())return 1 ;
    int & ret = dp[pos][flag][flagzero] ;
    if (ret !=-1 ) return ret ;
    ret = 0;
    for (int i= 0 ; i<10; i++){
        if (i==k && i==0 && flagzero== false)continue;
        if (i==k && i!=0) continue;
        if (i==s[pos]-'0' && i==0 && flagzero) ret += work (pos+1,flag,true);
        else if (i==s[pos]-'0') ret+= work( pos+1, flag,false);
        else if (i>s[pos]-'0' && flag==false)ret += work( pos+1, false,false);
        else if (i==0 && flagzero == true) ret += work (pos+1, false,true);
        else if (i<s[pos]-'0') ret += work (pos+1,false, false) ;
    }
    return ret ;
}
 
void Solve() {
    cin >> n >> k ;
    int lef = 0 , righ = INF , ans = - 1 ;
    while (lef<=righ){
        int md = lef + (righ-lef)/2 ;
        s=to_string(md) ;
        memset (dp, -1 , sizeof(dp)) ;
        int cnt = work (0,true,true) ;
        cnt-- ;
        if (cnt >= n){
            ans = md ;
            righ = md -1 ;
        }else lef = md +1 ;
    }
    assert ( ans != -1 ) ;
    cout << ans << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}