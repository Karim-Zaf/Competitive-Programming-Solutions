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

const int N = 3e5 + 30, mod = 1e9 + 7, MOD = mod, INF = 1e18 + 10;

void Solve() {

    int n , k;
    cin >> n >> k ;
    map<int,int> mpa , mpb  ;
    multiset<int> a[3], b[3], ansa, ansb;
    for (int i= 0 ,x ; i<n ; i++){
        cin >> x;
        mpa[x]++ ;
    }
    for (int i= 0 ,x ; i<n ; i++){
        cin >> x;
        mpb[x]++ ;
    }
    for (auto x: mpa){
        a[x.S].insert(x.F) ;
    }

    for (auto x: mpb){
        b[x.S].insert(x.F) ;
    }

    while (!a[2].empty()&&!b[2].empty()&& ansa.size()<2*k && ansb.size() <2*k ){
        int one = *a[2].begin() ;
        int two = *b[2].begin() ;
        a[2].erase(one) ;
        b[2].erase(two) ;
        ansa.insert(one);
        ansa.insert(one);
        ansb.insert(two);
        ansb.insert(two);
    }
    while (!a[1].empty()&&!b[1].empty()&& ansa.size()<2*k && ansb.size() <2*k ){
        int one = *a[1].begin() ;
        int two = *b[1].begin() ;
        a[1].erase(one) ;
        b[1].erase(two) ;
        ansa.insert(one);
        ansb.insert(two);
    }
    for (auto x: ansa) cout << x << " " ; cout << endl;
    for (auto x: ansb) cout << x << " " ; cout << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}