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
#define endl '\n'

const int N = 5e3 + 3, MOD = 1e9 + 7, mod = 1e9 + 7, INF = 1e18 + 10;

int dp[N][N], mx[N][N] ;


void Solve() {
    ll n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), indx(n+4);
    map<int, int> mp ;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]] = 1;
    }

    int timer = 0; // compressing the values of v 
    for (auto x: mp)mp[x.F] = ++timer;

    for (int i= 1; i<=n ;i++){
        v[i]= mp[v[i]];
        indx[v[i]]= i ;
    }

    for (int r = 1; r <= n; r++) // calculating the maximum in each range
        for (int l = r; l >= 1; l--) 
            mx[l][r]= max(v[l],mx[l+1][r]);
    

    vector<int> nw ;
    for (int i= 1; i<=n ;i++) nw.pb(v[i]) ;
    sort (all(nw));

    for (int r = n; r >= 1; r--) {
        vector<int> curr = nw , nxt(n+2);
        
        //calculating for each postion the farest element smaller than me 
        for (int l = r; l >= 1; l--){ 
            while(!curr.empty() && v[l]<=curr.back()){
                nxt[indx[curr.back()]]= l ;
                curr.pop_back();
            }
        }

        // nxt[i] res presentes the postion p such that mx(l->pos)<= mn(pos+1,r)
        //l->pos we will sort it using sort (pos,l) ans (pos+1,r) is calculated in the dp 
        for (int l = r; l >= 1; l--) {
            dp[l][r]= r-l ;
            nxt[l]= nxt[indx[mx[l][nxt[l]]]];

            int pos = nxt[l] ;

            pos = min (pos,r);
            dp[l][r]= min( dp[l][r],pos - l + dp[pos+1][r]) ;

            ans += dp[l][r];
        }
        vector<int> nw_nw ;
        for (auto x: nw) if (x!=v[r])nw_nw.pb(x);
        nw = nw_nw;
    }
    cout << ans << endl;
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