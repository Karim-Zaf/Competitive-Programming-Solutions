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
    int n , m ;
    cin >> n>> m ;
    vector <ld> l(n) , r(n) ;
    ld s1=0 , s2 = 0 ;
    for (int i= 0 ;i<n;i++) cin >> l[i]>> r[i] ;
    auto ok = [&](double a ){
        ld res = 0 ;
        for (int i= 0 ;i<n;i++){
            if (a>= r[i]) {res +=1 ;continue;}
            if (a<=l[i]) continue;
            res += (a-l[i])/ (r[i]-l[i]) ;
        }
        return res ;
    };
    ld  lef = 0 , righ = 1e9+1 , res = 0;
    while (abs(righ- lef)>=0.000001){
        ld md = lef + (righ -lef)/2;
        if (ok(md)>=m){
            res = md ;
            righ = md ;
        }else lef = md;
    }
    cout << fixed << setprecision(9)<< res  << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}