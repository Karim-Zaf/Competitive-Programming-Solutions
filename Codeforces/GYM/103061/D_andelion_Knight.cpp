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
#define ld long double
const ll N = 1e6+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e9+5;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n+2) , b(n+2) , deb (n+2,-1) , fin (n+2,-1), res ( 2*n+1);
    for (int i= 1 ;i<=n ;i++) cin >> a[i]  ;
    for (int i= 1 ;i<=n ;i++) cin >> b[i]  ;

    for (int i= 1 ;i<=n ;i++) a[i]+=a[i-1]  ;
    for (int i= 0 ;i<=n ;i++) {
        if (i)b[i]+=b[i-1]  ;
        if (deb[b[i]] == -1) deb[b[i]]= i;
        fin [b[i]]=i ;
    }
    for (int i= 0 ; i<=n ; i++){
        if (deb[a[i]]==-1) continue;
        res[i + deb[a[i]]]+=1 ;
        if (i+ fin[a[i]]+1 <=2*n) res[i+fin[a[i]]+1]+= -1 ;
    }
    for (int i= 1 ; i<= 2*n ; i++) res[i]+= res[i-1] ;
    for (int i= 0 ;i<= 2*n ;i++) cout << res[i] << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}