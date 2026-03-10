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
 
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve() {
    int n , k , sum = 0 ;
    cin >> n >> k ;
    vector <int> v(n+2) , pref(n+2), ans;
    for (int i=1 ; i<=n ; i++) cin >> v[i] ;
    for (int i=1 ; i<=n-k ; i++) {
        pref[i]+=pref[i-1];
        if (pref[i]%2) v[i]^=1 ;
        if (v[i]==0) {
            pref[i] += 1, pref[i + k] += -1;v[i]=1 ;
            ans.pb(i);
        }
    }
    for (int i= n-k+1 ; i<= n;i++){
        pref[i]+=pref[i-1];
        if (pref[i]%2) v[i]^=1 ;
        sum += (v[i]==0) ;
    }if (sum >k/2) ans.pb(n-k+1);
    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " " ; cout << endl;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}