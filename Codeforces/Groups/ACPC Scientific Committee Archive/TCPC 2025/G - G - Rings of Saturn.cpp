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
    int n, m;
    cin >> n >> m;
 
    int t[n][m];
    for (int i = 0; i < n; i++){ for (int j = 0; j < m; j++){ cin >> t[i][j]; } }
 
    for (int j = 0; j < m; j++){
        vector<int> curr;
        for (int i = 0; i < n; i++)
            curr.push_back(t[i][j]);
        sort(all(curr));
        for (int i = 0; i < n; i++)
            t[i][j] = curr[i];
    }
 
    vector<int> indx(m);
 
    int ans = 0;
    for (int i = 0; i < n; i++){
        int lst = -INF;
        bool ok = true;
 
        for (int j = 0; j < m; j++){
            while (indx[j] < n && t[indx[j]][j] < lst)indx[j]++;
            if (indx[j] >= n)
                ok = false;
            else{
                lst = t[indx[j]][j];
                indx[j]++;
            }
        }
 
        ans += ok;
    }
 
    cout << ans << endl;
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