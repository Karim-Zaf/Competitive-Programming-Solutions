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


int convert (string s){
    int ret = 0;
    reverse(all(s));
    for (int j=s.size()-1;j>=0;j--)
        ret+= (1<<j) * (s[j]-'0');
    return ret;
}

int query [1<<12][105], mp[1<<12];

void Solve() {
    int n , q , m ;
    cin >> n >> m >> q ;
    vector<int> w(n) ;
    for (auto &x:w)cin>>x;
    reverse(all(w));
    for (int i= 0  ; i<m ; i++){
        string s;cin>>s;
        int x= convert(s);
        mp[x]++ ;
    }
    for (int j= 0 ; j<(1<<n) ; j++){
        for (int a= 0 ; a <(1<<n) ; a++){
            int cnt = 0;
            for (int k = 0 ; k<n ;k++)
                cnt += (((1<<k)&j)==((1<<k)&a))*w[k];
            if (cnt >100) continue;
            query[j][cnt]+=mp[a];
        }
        for (int i= 1 ; i<=100; i++)
            query[j][i]+= query[j][i-1];

    }
    while (q--){
        string s ; int k ;
        cin >> s >> k ;
        int curr = convert(s);
        cout << query[curr][k]<< endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}