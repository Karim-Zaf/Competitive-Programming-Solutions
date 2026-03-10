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

int work (string s){
    int n =s.size() ;
    string oth="";
    for (int i= 0 ; i<=n; i++) oth+="0";
    for (int i= 0;i<n; i++){
        int cnt = 0 , flag = 0, nwsz =0 ;
        for (int j = i; j>=0 ; j--){
            cnt += (oth[j]=='1');
            nwsz++;
            if (cnt >= (nwsz+1)/2)flag = 1;
        }
        if (!flag && s[i]=='1') oth[i+1]='1';
    }

    return count(all(oth),'1');
}

void Solve() {
    int n , ans = 0;
    string s ;
    cin >> n >> s ;
    for (int i= 0 ; i<n ;i++){
        for (int j= 0 ; j<=i ;j++){
            string st ="";
            for(int k = j ; k<=i ;k++) st+=s[k];
            ans += work(st);
        }
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}