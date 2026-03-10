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

const ll N =1e6+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e9;

void solve() {
    int n , sum = 0 , q ;
    cin >> n;
    vector <int> v(n+1) ;
    for (int i= 1 ; i<=n ;i++) cin >> v[i];
    sum = v[1];
    for (int i= 2 ; i<=n ;i++) sum= v[i]-sum;
    cin >> q ;
    while (q--){
        int l , r , x ;
        cin >> l >> r>> x;
        int pair = r/2 - (l-1)/2 ;
        int impair = (r-l+1) -pair ;
        if (n%2) {
            sum -= pair*(x);
            sum += impair *(x);
        }else {
            sum += pair * (x);
            sum -= impair * (x);
        }
        cout << sum << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}