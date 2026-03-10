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
 
const ll N = 1e12+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
 
void solve (){
    int n ,curr = 0 ;
    cin >> n ; 
    vector <int> a(n) , b(n) , nw(n) , pos(n+1,-1);  
    for (auto &x: a) cin >> x ; 
    for (auto &x: b) cin >> x ; 
    for (int i= 0 ;i<n ;i++) pos[a[i]]=i ;
    for (int i= 0 ;i<n ;i++) nw[i]=pos[b[i]] ;
    set<int> s ;
    for (int i= 0;i<n;i++){
        auto it = s.lower_bound(nw[i]);
        if (it == s.end()) s.insert(nw[i]);
        else {
            s.erase(*it);
            s.insert(nw[i]);
        }
    }
    cout << s.size()  << endl;

}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}