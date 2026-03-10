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

const int N = 5e3 + 5, mod = 1e9 + 7, INF = 1e18 + 10;

int dp[N];
int best[N];
int a[N];
int n;

int work(int pos){
    if (pos == 0) return 0;
    int& ret = dp[pos];
    if (ret!=-1)return ret ;

    // keep
    ret =  a[pos] +  work(pos - 1);

    // naatehom
    for (int indx = pos ; indx>= 1 ;indx --){
        ret = min( ret, (pos - indx ) + a[pos]*(pos -indx +1) + work (indx -1 ));
    }

    // nekhou
    int indx = best[pos];
    for (int indx = pos ; indx>= 1 ;indx --){
        ret = min(ret, 2 * (pos - indx) + a[indx] * (pos - indx) + work(indx));
    }

    return ret;
}

void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];

    for (int i = 1; i <= n; i++){
        best[i] = i;
        for (int j = i; j >= 1; j--){
            auto count = [&](int indx){ return (i - indx) + a[indx]; };
            if (count(j) <= count(best[i])){ best[i] = j; }
        }
    }

    for (int i = 0; i <= n; i++) dp[i]=-1;
    cout << work(n) << endl;
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
