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

    int n ;
    cin >> n ;
    bool ok = false ;
    string ans="";
    char t[2][n] ;
    for (int i= 0 ; i<2 ; i++)
        for (int j= 0 ; j<n ;j++)
            cin >> t[i][j];
    ans += t[0][0];
    for (int i= 0 ; i<n ;i++){
        if (ok) ans += t[1][i];
        else {
            if (i==n-1){
                ok = true ;
                ans+= t[1][i];
            }
            else if (t[0][i+1]==t[1][i]||t[0][i+1]=='0'){
                ans+=t[0][i+1];
            }
            else {
                ok = true;
                ans+=t[1][i];
            }

        }

    }
    vector<int> pref (n) ,suff(n) ;
    pref[0]=(ans[0]==t[0][0]) ;
    suff[n-1]= (ans.back()==t[1][n-1]);
    for (int i= 1 ; i<n ;i++){
        if (t[0][i]!=ans[i])pref[i]=0 ;
        else pref[i]=pref[i-1] ;
    }
    for (int i= n-2 ; i>=0 ;i--){
        kar (ans[i+1]);
        kar (t[1][i]);
        if (t[1][i]!=ans[i+1])suff[i]=0 ;
        else suff[i]=suff[i+1] ;
    }
    kar (suff);
    int res = 0 ;
    for (int i= 0 ; i<n ;i++)res += (pref[i]&suff[i]);

    cout << ans << endl<<res << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}