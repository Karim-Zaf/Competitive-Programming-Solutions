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
const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){

    ld n , d , h ;
    cin >> n >> d >> h ;
    vector <ll> v(n) ;
    for (int i= 0 ;i<n ;i++)
        cin >> v[i];
    ld res = (ld)(n) *(((ld)(d*h)/(ld)(2)));

    for (int i = 1 ; i<n ;i++ ){
        ld diff = (v[i]-v[i-1]);
        ld height = h - diff;
        if (height <0) continue;
        ld base =(ld)(height) /h;
        base *= (d/(ld)(2));
        base *=2 ;
        ld area = (((ld)(base*height)/(ld)(2)));

        res -= area ;

    }
    cout <<fixed << setprecision(6) <<  res <<  endl;

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