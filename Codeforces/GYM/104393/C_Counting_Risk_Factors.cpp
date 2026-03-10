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
 
const ll N =1e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
 
void solve(){
    int n , k , l ,res = 0;
    string s1 , s2 ;
    cin >> n >> k >> l >> s1 >> s2 ;
    vector<int> pref(n) , mp(n+3);
    mp[0]++ ;
    for (int i= 0 ; i<n ;i++){
        for (auto c : s2) if (c==s1[i]) pref[i]=1 ;
        if (i) pref[i]+= pref[i-1];
        if (pref[i]-k>=0)res += mp[pref[i]-k];
        mp[pref[i]]++ ;
    }
    cout << res << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}