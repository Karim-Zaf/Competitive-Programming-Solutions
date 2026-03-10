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
#define ld long double
const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

string s ;
int n , x ;
map<int,int> dp[2], vis[2];
int fact[15]{1};

int work (int mask , int flag){
    if (mask ==(1ll<<n)-1)return 1ll;
    int &ret =dp[flag][mask] ;
    int &vs = vis[flag][mask];
    if (vs)return ret;
    vs = 1 ;
    int pos = __builtin_popcount(mask);
    for (int i= 0 ; i<n;i++){
        if (mask & (1ll<<i))continue;
        if (s[i]<s[pos] && !flag) continue;
        int nwflag = flag| (s[i]>s[pos]);
        ret+= work(mask+(1ll<<i),nwflag);
    }
    return ret ;
}

void Solve() {
    cin >> x ;
    s = to_string (x);
    n = s.size();
    vector<int> mp(10);

    dp[0].clear(), dp[1].clear(),vis[0].clear(),vis[1].clear();
    int nb = work(0,0)-1 ;

    int nballperm =fact[n];

    for (auto c: s) mp[c-'0']++;
    for (int i= 0 ;i<10;i++)nballperm/= fact[mp[i]];

    ld sum = 1 , prob = 1/(ld)(nballperm), ans = 0;

    vector<ld> dpp(nb+1);

    for (int i= 0 ;i<nb ;i++){
        ans= sum*prob;
        sum+= ans;
    }


    cout << fixed<< setprecision(9)<< ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    for (int i= 1; i<=14; i++) fact[i]= i*fact[i-1] ;
    cin >> Test_case;
    while (Test_case--) Solve();
}