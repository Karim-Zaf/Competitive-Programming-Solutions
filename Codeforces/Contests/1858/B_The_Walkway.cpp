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
    int n , m , d , res= 0 ;
    cin >> n>> m >> d ;
    vector <int> v(m +3,1) , kodemi (m+3,1) , teli (m+3,1), ans;
 
    for (int i= 1 ; i<=m;i++) cin >> v[i];
    teli [0]=(v[1]!=1) ; v[m+1]=n+1;
    for (int i= 1 ; i<=m;i++)teli[i]+= max(0ll,v[i]-v[i-1] -1)/d + teli[i-1];
    for (int i= m ; i>=1;i--)kodemi[i]+= max(0ll,v[i+1]-v[i] -1)/d + kodemi[i+1];
    for (int i= 1 ; i<=m;i++) ans.pb( max(0ll,v[i+1]-v[i-1] -1)/d+ teli[i-1]+ kodemi[i+1]+(v[i]==1));
    sort (all(ans)) ;
    int curr = ans[0] , i= 0 ;
    while (ans[i]==curr && i < m) {res ++ ; i++;}
    cout << --curr << " " <<res << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}