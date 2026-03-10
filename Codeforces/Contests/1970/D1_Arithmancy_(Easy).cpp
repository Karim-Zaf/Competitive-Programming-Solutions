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


void Solve() {
    int n;
    cin >> n;

    pair<int, int> val[10000];
    string s[5];

    s[1] = "OXOO", s[2] = "XXXXOOOO", s[3] = "OOXOOX";
    for (int i = 1; i <= n; i++) {
        cout << s[i] << endl;
        cout.flush();
    }
     int q ; cin >> q ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            string cur = s[i] + s[j];
            set<string> st;
            for (int l = 0; l < (int) cur.size(); l++) {
                string g = "";
                for (int r = l; r < (int) cur.size(); r++) {
                    g += cur[r];
                    st.insert(g);
                }
            }
//
            int sz = st.size();
//            if (val[sz] != make_pair(0ll , 0ll)){
//                kar (cur) ;
//                kar (s[val[sz].F]+s[val[sz].S])
//            }
           assert(val[sz] == make_pair(0ll , 0ll)) ;

            val[sz] = {i, j};
        }
    }
//    kar("");
//     cout << val[1]
     while(q--){
         int p ;
         cin >> p ;
         cout << val[p].F << " " << val[p].S << endl;
         cout.flush() ;
     }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}