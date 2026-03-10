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
//#define int ll

const ll N = 1e6+ 5 ,  MOD =1e9+7, mod=998244353, INF = 1e18+5;

vector<int> factors(int n){
    vector<int> res;
    for(int i = 2; i*i <= n;i++){
        if(n % i) continue;
        res.push_back(i);
        while(n % i == 0)  n /= i;
    }if(n > 1)res.push_back(n);
    return res;
}

void solve(){
    int n , m ;
    cin >>n >> m ;
    vector <ll> v(n)  ;
    for (auto &x: v) cin >> x;
    ll res = 1;
    auto work =[&] (int a , int gcd)->int{
        if (a%gcd) return 0 ;
        vector <int> f = factors(a/gcd);
        int mm = m/gcd , sz = f.size(), ret = 0;
        for (int i = 1 ; i<(1<<sz) ; i++){
            int cnt = 0 , prd = 1 ;
            for (int j = 0 ; j<sz ; j++){
                if (i& (1<<j)){
                    prd *= f[j] ;
                    cnt ++ ;
                }
            }
            if (cnt %2) ret += mm / prd ;
            else ret -= mm / prd ;
        }
        return mm - ret ;
    };

    for (int i= 1 ; i<n ;i++){
        res *= work (v[i-1] , v[i]);
        if (res == 0 ) {cout << "0\n";return ;}
        res %= mod ;
    }
    cout << res << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}