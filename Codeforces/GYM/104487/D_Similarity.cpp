/*                 __                __         __
     | | / /  /  \  | | |   \  | |  | |      |  |  /  \   |  _|
     | |/ /  | || | | | | || | |  /  |         / /  | || |  | |__
     |   /   |    | | | |   /  | |/| |        / /   |    |  |  |
     | |\ \  | | | | | | | | \ \ | |  | |       / /  | | | |  | |
     || _\ || || || || || ||  ||      |__| || ||  ||      */
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

const ll N = 2e6+ 5 ,  MOD =1e9+7, mod=1e9+7, INF = 5e18 ;

void solve(){
    int n , m , res =0;
    cin >> n>> m ;
    vector <string> v(n) ;
    for (int i= 0 ; i<n ;i++) cin >> v[i] ;
    for (int j= 0 ; j<m ; j++){
        int mx = 0 ;
        for (char c = 'a' ; c<='z' ; c++){
            int cnt = 0;
            for (int i= 0; i<n ;i++)
                if (c==v[i][j]) cnt ++;
            mx = max (cnt , mx);
        }
        res += mx ;
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}