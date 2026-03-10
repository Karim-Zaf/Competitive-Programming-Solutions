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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;


int v(int e) { return (1 << e); }
void Solve() {
    vector<int> value(30) ;
        value[0] = v(0) + v(1) + v(2) + v(3) + v(4) + v(5);
        value[1] = v(1) + v(2);
        value[2] = v(0) + v(1) + v(3) + v(4) + v(6);
        value[3] = v(0) + v(1) + v(2) + v(3) + v(6);
        value[4] = v(1) + v(2) + v(5) + v(6);
        value[5] = v(0) + v(2) + v(3) + v(5) + v(6);
        value[6] = v(0) + v(2) + v(3) + v(4) + v(5) + v(6);
        value[7] = v(0) + v(1) + v(2);
        value[8] = v(0) + v(1) + v(2) + v(3) + v(4) + v(5) + v(6);
        value[9] = v(0) + v(1) + v(2) + v(3) + v(5) + v(6);
    map<int,int> mp ;

    int ans = 0 ;
    int n ;
    cin >> n;
    string s ;
    cin >> s;
    for (int i= 0 ; i<n/2  ;i++){
        char c ;
        int mn = INF ;
        int one = s[i]-'0', two = s[n-i-1]-'0' ;
        for (int j = 0 + (i==0) ; j<=9; j++){
            int cost = __builtin_popcount(value[j]^value[one]) ;
            cost += __builtin_popcount(value[j]^value[two]) ;
            if (cost < mn ){
                c = char (j+'0') ;
                mn  = cost ;
            }
        }
        ans += mn ;
        s[i]= s[n-i-1] = c ;
    }
    cout << ans << endl;
    cout << s << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0),cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}