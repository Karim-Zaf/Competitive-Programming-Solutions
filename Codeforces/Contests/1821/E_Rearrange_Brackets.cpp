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

void Solve(){
    int k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < k; i++){
        vector<int> indx(s.size() + 3);
        vector<pair<char,int>> st;
        pair<int,int> p = {0, 0};
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ')'){
                auto [c,blasa] = st.back();
                indx[i] = blasa;
                if (i - blasa >= p.S - p.F) p = {blasa, i};
                st.pop_back();
            }
            else{ st.push_back({s[i], i}); }
        }

        string nw_s = "";
        for (int i = 0; i < s.size(); i++){
            if (i == p.F) continue;
            if (i == p.S)nw_s += s[p.F];
            nw_s += s[i];
        }
        s = nw_s;
    }

    reverse(all(s));
    int cnt = 0 , ans = 0 ;
    for (auto &x: s){
        if ( x == '('){
            cnt --;
            ans += cnt;
        }else{
            cnt ++;
        }
    }

    cout << ans << endl;
}


int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
