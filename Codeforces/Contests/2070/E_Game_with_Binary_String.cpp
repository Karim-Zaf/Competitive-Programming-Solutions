/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/* order_of_key(x): counts the number of elements in the set that are
strictly less than x.
find_by_order(k): similar to find, returns the iterator corresponding
to the k-th lowest element in the set (0-indexed).*/

void Solve() {
    /*
     * I win when the second guy have only zeros or one character '1'
     * */
    int n, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
//    vector<pair<int,int>> vp ;
//    for (int i= 0 ;i<n; i++){
//        for (int j= 0 ; j<i ;j++){
//            string curr = "";
//
//            for(int k= j ; k<=i ; k++) curr += s[k];
//            int cnt[2]= {0};
//            cnt[0]= count(all(curr),'0');
//            cnt[1]= count(all(curr),'1');
//            if (cnt[0]== 3*cnt[1]-1 || cnt[0]>3*cnt[1]+1 ){
//                vp.pb({j+1,i+1});
//            }
//        }
//    }
//    sort (all(vp)) ;
//    kar (vp);

    vector<vector<int>> pref(2, vector<int>(n + 3));
    s = "#" + s;

    indexed_set seti;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        pref[s[i] - '0'][i] = 1;
        for (int j = 0; j < 2; j++) {
            pref[j][i] += pref[j][i - 1];
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {

        mp[-3 * pref[1][i - 2] + pref[0][i - 2] - 1]++;
        seti.insert({-3 * pref[1][i - 2] + pref[0][i - 2] + 2, ++cnt});

        pair<int, int> p{pref[0][i] - 3 * pref[1][i], INF};

        ans += seti.order_of_key(p);
        ans += mp[pref[0][i] - 3 * pref[1][i]];

    }

    cout << ans << endl;

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