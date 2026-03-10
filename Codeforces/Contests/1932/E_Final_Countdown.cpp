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
    int n , sum = 0, alll =0;
    string s ;
    cin >> n >> s;
    for (auto x: s){
        sum +=( x-'0');
    }
    string ans = "";
    alll= sum ;
    for (int i= n-1 ; i>=0  ; i-- ){
        ans += char(alll%10+'0');
        sum -= (s[i]-'0');
        alll/=10;
        alll += sum;
    }
    string j =to_string (alll) ;
    reverse(all(ans));
    ans= j+ans;
    int pos = 0 ;
    n = ans.size();
    while(pos<n-1&&ans[pos]=='0')pos++;
    for (int r= pos ; r<n ;r++) cout << ans[r] ; cout << endl;



}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}