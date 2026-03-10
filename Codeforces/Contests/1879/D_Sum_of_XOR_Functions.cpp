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

const int  N=2e5+8,MOD=998244353,mod=998244353,INF=1e18;



void Solve(){
    int n, res = 0 ;
    cin >> n ;
    vector<int> v(n ) ;
    for (int i= 0 ;i<n ;i++)cin >> v[i] ;
    for (int b= 30; b>=0; b--){
        vector <int> ones , ans , nb ;
        int cnt = 0;
        for (int i= 0  ;i<n ;i++){
            if (!(v[i]&(1<<b))) {
                if (ones.size()>=1)
                cnt+= ans[ones.size()-1]+ nb[ones.size()-1]*(i-ones[ones.size()-1])  ;
                cnt%= mod ;
                continue;
            }
            int nw_ans= 0, nbb=  0 ;
            if (ones.size()==0) {
                nw_ans += (i+2)*(i+1)/2 ;
                nbb+= i+1;
            }else {
                nw_ans += (i-ones.back())*((i-ones.back())+1)/2;
                nbb+= (i-ones.back()) ;
                nbb+= ones.back()+1 -nb.back();

            }
            if (ones.size()>=2){
                nw_ans+= ans[ones.size()-2]+ nb[ones.size()-2]*(i-ones[ones.size()-2])  ;
            }
            nw_ans%=mod;
            ones.pb(i);
            nb.pb(nbb);
            ans .pb(nw_ans);
            cnt += nw_ans ;
            cnt%=mod ;
        }
        res += (cnt * (1<<b))%mod ;
        res %= mod;
    }
    cout << res << endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while(Test_case--)Solve();
}