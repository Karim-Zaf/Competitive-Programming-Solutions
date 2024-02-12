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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

array<ll,2> a[N] ;
map<ll,vector<array<ll,4>>> f ;
map<array<ll,4> , ll> g ;


array<int,4> eq (array<ll,2> c, array<ll,2>b){
    ll y = c[1] - b[1] , x = c[0] - b[0] ;
    ll gg = abs(__gcd(y , x)) ;
    if(x < 0) y *= -1 , x *= -1 ;
    if(gg)y /= gg , x /= gg ;
    ll b1 = c[1] * x - y * c[0] , b2 = x ;
    gg = abs(__gcd(b1 , b2)) ;
    if(b2 < 0) b1*=-1 , b2*=-1 ;
    if(gg)b1 /= gg , b2/=gg ;
    if (x==0) y=1,b1=0,b2=c[0];
    return {y , x , b1 , b2};
}

void Solve(){
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i][0] >> a[i][1] ;

    for(int i = 1 ; i + 1 <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            array<int,4> d = eq(a[j],a[i]);
            g[d]++ ;
            f[i].push_back(d) ;
        }
    }
    ll ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        for(auto r : f[i]){
            g[r]-- ;
        }
        for(int j = 1 ; j < i ; j++){
            array<int,4> d = eq(a[j],a[i]);
            ans += g[d] ;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
