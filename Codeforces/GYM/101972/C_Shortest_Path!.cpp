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
 
const ll N = 1e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
 
 
ld a , b , c , x;
 
void solve(){
    cin >> a >> b >> c >> x ;
    double res= 0;
    res += sqrt(a*a + (2*c+b)*(2*c+b));
    res += x/100.0 * sqrt(a*a + b*b);
    double e = a - a*x/100.0;
    double chwayya = b - b*x/100.0;
    res+= sqrt(e*e + (chwayya +2*c)*(chwayya + 2*c));
    cout << fixed << setprecision(9) << res<< endl;
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}
 
// Failure gives you two choices: You stay down or You get up ;)