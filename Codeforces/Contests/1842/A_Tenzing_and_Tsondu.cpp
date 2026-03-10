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

const ll N = 5e5+ 7 , MOD =998244353, mod=998244353, Q =2e5+4 , INF = 1e18 ;

void solve (){
    int n , m ; 
    cin >> n >> m ; 
    vector <int> a(n) , b(m) ; 
    for (auto &x : a) cin >> x ; 
    for (auto &x : b) cin >> x ; 
    sort (all(a)) ; 
    sort(all(b)) ; 
    int i = n-1 , j= m-1 ;
    while (i>=0 && j>=0){
        int curr = a[i];
        a[i]= a[i]-b[j];
        b[j]= b[j] -curr;
        if (b[j]<=0)j--;
        if (a[i]<=0) i--;
    }
    if(i==-1 && j ==-1 ) cout << "Draw" << endl;
    else if(i==-1) cout << "Tenzing" << endl;
    else cout << "Tsondu" << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}