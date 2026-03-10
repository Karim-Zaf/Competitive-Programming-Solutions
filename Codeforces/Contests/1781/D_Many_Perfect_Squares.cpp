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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+6;


void Solve() {
    int n ,res =1 ;
    cin >> n ;
    vector <int> v(n);
    set <int> s , possible;
    for (auto &x: v) cin >> x ;
    for (int i= 0; i<n;i++)
        for (int j= 0;j <n; j++) {
            int d =abs(v[i] - v[j]);
            for (int k = 1; k * k <= d; k++) {
                if (d % k) continue;
                int one = k, two = d / k;
                int s_one = one + two;
                int s_two = two -s_one/2 ;
                if (s_one % 2 == 0 && s_two >=0){
                    s_one/=2;
                    if (v[i]-s_one*s_one==v[j]-s_two*s_two && v[i]-s_one*s_one<=0)
                        possible.insert(v[i]-s_one*s_one);
                    else if (v[j]-s_one*s_one<=0)possible.insert(v[j]-s_one*s_one);
                }
            }
        }
    
    for (auto x : possible){
        int cnt = 0 ;
        for (int i = 0 ; i<n; i++){
            int curr = sqrtl (v[i]-x);
            cnt+= (curr*curr == v[i]-x) ;
        }
        res = max (res , cnt );
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}