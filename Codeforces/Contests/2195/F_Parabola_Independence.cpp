/*  ██╗  ██╗ █████╗ ██╗██████╗ ███╗   ███╗        ███████╗ █████╗ ███████╗
    ██║ ██╔╝██╔══██╗██║██╔══██╗████╗ ████║        ╚══███╔╝██╔══██╗██╔════╝
    █████╔╝ ███████║██║██████╔╝██╔████╔██║          ███╔╝ ███████║█████╗
    ██╔═██╗ ██╔══██║██║██╔══██╗██║╚██╔╝██║         ███╔╝  ██╔══██║██╔══╝
    ██║  ██╗██║  ██║██║██║  ██║██║ ╚═╝ ██║███████╗███████╗██║  ██║██║
    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝     */
#include <bits/stdc++.h>
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve(){
    int n;
    cin >> n;
    vector<array<int, 4>> v(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3; j++) cin >> v[i][j];
        v[i][3] = i;
    }
    bool intersect[n + 1][n + 1];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            intersect[i][j] = false;
            if (v[i] == v[j]){
                intersect[i][j] = true;
                continue;
            }

            auto [a1,b1,c1,i1] = v[i];
            auto [a2,b2,c2,i2] = v[j];

            int a = a1 - a2;
            int b = b1 - b2;
            int c = c1 - c2;
            if ( a== 0 && b== 0 )continue;

            int delta = b * b - 4 * a * c;

            intersect[i][j] = delta >= 0;
        }
    }


    sort (v.begin()+1,v.end());

    vector<int> dp(n + 1,1), pref(n+2,1),suff(n+2,1);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            auto& [a1,b1,c1,i1] = v[i];
            auto& [a2,b2,c2,i2] = v[j];
            if (!intersect[i1][i2]){ pref[i1] = max(pref[i1], pref[i2] + 1); }
        }
    }
    for (int i = n ; i>=1 ; i--){
        for (int j = i+1; j <=n; j++){
            auto& [a1,b1,c1,i1] = v[i];
            auto& [a2,b2,c2,i2] = v[j];
            if (!intersect[i1][i2]){ suff[i1] = max(suff[i1], suff[i2] + 1); }
        }

    }

    for (int i= 1;i<=n ; i++){
        dp[i]= pref[i]+ suff[i]-1;
    }

    for (int i = 1; i <= n; i++)cout << dp[i] << " ";
    cout << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
