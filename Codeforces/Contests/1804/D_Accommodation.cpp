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

int work1 (string &s){
    int n = s.size() , i = 0, cnt= 0,other= 0;
    while (i<n){
        if (cnt <n/4 && i+1<n && s[i]==s[i+1] &&s[i]=='1'){i+=2; cnt ++;}
        else {other+= (s[i]=='1');i++;}
    }
    return other + cnt ;
}

int work2 (string &s){
    int m = s.size() , i = 0, cnt= 0,dble = 0, one =0, zero = 0;
    vector<int> vis(m);
    while (i<m){
        if ((dble+cnt) <m/4 && (i+1)<m && s[i]==s[i+1] && s[i]=='0'){dble++;vis[i]=vis[i+1]=1;i+=2;}
        else if ((dble+cnt)<m/4 && (i+1)<m && s[i]!=s[i+1]){vis[i]=vis[i+1]=1 ;i+=2;cnt++;}
        else i++;
    }
    i= 0;
    while (i<m){
        if (dble+cnt<m/4 && i+1<m &&!vis[i]&&!vis[i+1]&&s[i]==s[i+1]&&s[i]=='1'){cnt++;i+=2;}
        else if (!vis[i] &&s[i]=='1'){i++;one++;}
        else i ++ ;
    }
    return cnt +one ;
}


void Solve() {
    int n , m , mn = 0, mx = 0;
    cin >> n >> m ;
    for (int i= 0 ; i<n ; i++){
        string s ;
        cin >> s;
        mn += work1(s);
        mx += work2(s);
    }
    cout << mn << " " << mx << endl;
}


int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}