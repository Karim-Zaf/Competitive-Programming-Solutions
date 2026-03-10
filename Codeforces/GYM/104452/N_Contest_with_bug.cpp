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
const ll N =1e7+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

void solve(){
    int k ,n ;
    cin >> k >> n ;
    pair <int , int> ans = {-1,INF};
    vector <int> a(n), v(n) ;
    for (auto &x: v) cin >> x;

    for (int i= 0 ; i<=n; i++){
        for (int j= 1; j<=  n ;j++) a[j-1]=j ;
        do {
            int sum1 =0, sum2 =0, cnt = 0;
            for (int j= 0; j<n ;j ++){
                sum1 +=  max (0ll,a[j]-i)*v[j];
                sum2 += min (1ll,max (0ll,a[j]-i))*v[j];
                cnt += min (1ll,max (0ll,a[j]-i));
            }
            sum1%=1440;
            if (cnt>ans.F&& sum2<=k||cnt==ans.F && sum1<=ans.S && sum2<=k) ans={cnt ,sum1};
        }while(next_permutation(all(a)));
    }

    cout << (ans.F==-1 ? 0: ans.F ) << " " <<  (ans.S==INF ? 0: ans.S )  << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}