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

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n , res = 0;
    cin >> n ;
    vector <string> s (n) ;
    map <int,int> mp[80] ;
    for (int i= 0 ; i<n ;i++) {
        cin >> s[i] ;
        int all= 0 ;
        for (int j= 0 ; j<s[i].size() ; j++) all += ( s[i][j]-'0');
        mp[s[i].size()][all]++;
    }
    sort (all(s),[](string a , string b){return a.size()>b.size();});
    for (int i= 0 ; i<n ;i++) {
        cin >> s[i] ;
        int pref= 0 , all = 0;
        for (int j= 0 ; j<s[i].size() ; j++)all += (s[i][j]-'0');

        mp[s[i].size()][all]--;
        for (int j= 0 ; j<s[i].size() ; j++){
            pref += ( s[i][j]-'0');
            int sz_reste = 2ll*(j+1) - s[i].size();
            if (sz_reste <=0) continue;
            res += mp[sz_reste][2*pref-all];
        }
        reverse(all(s[i]));
        pref = 0;
        for (int j= 0 ; j<s[i].size() ; j++){
            pref += ( s[i][j]-'0');
            int sz_reste = 2ll*(j+1) - s[i].size();
            if (sz_reste <=0) continue;
            res += mp[sz_reste][2*pref-all];
        }
    }
    cout << res +n   << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}