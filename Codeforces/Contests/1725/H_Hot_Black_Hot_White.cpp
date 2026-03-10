/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
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
#define endl '\n'
#define int ll
 
const ll N =1e4 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve(){
    int n ;  string ret ="";
    cin >> n ;
    for (int i=0 ; i<n ; i++)ret+='#';
    vector <int> v(n) , mp[3] , cnt(2);
    for (int i= 0 ; i<n; i++) {
        cin >> v[i] ;
        mp[v[i]%3].pb(i) ;
    }
    // cas 1
    if(mp[1].size() + mp[2].size()<=n/2) {
        for (auto pos: mp[1]) { ret[pos] = '0';cnt[0]++; }
        for (auto pos: mp[2]) { ret[pos] = '0'; cnt[0]++ ;}
        for (int i= 0 ; i<n;i++){
            if (ret[i]=='#' && cnt[0]<n/2){ret[i]='0';cnt[0]++ ;}
            else if (ret[i]=='#'){ret[i]='1'; cnt[1]++ ;}
        }
        cout <<2<< endl<<  ret << endl; return;
    }
    // cas 0
    if (mp[0].size()<=n/2){
        for (auto pos: mp[0]) { ret[pos] = '0';cnt[0]++; }
        for (int i= 0 ; i<n;i++){
            if (ret[i]=='#' && cnt[0]<n/2){ret[i]='0';cnt[0]++ ;}
            else if (ret[i]=='#'){ret[i]='1'; cnt[1]++ ;}
        }
        cout <<0 << endl<< ret << endl; return;
    }
    cout << -1 << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}