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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int ask (int l , int r ){
    cout << l << " " << r << endl;
    cout.flush();
    int ret ;
    cin >> ret ;
    return ret;
}


void Solve() {

    int n , k ;
    cin >> n >> k;

    int ans_best = k ;
    for (int pos= n ; pos>=1; pos--){
        int prev =0 , best=0 ,nw_best =ans_best;
        
        for(int i =1; i<1<<pos; i++){
            //gray code
            int curr = i^(i>>1);
            int ans =ask (log2(curr^prev)+1,pos);
            if (ans>nw_best) {
                best = curr ;
                nw_best = ans;
            }
            prev =curr;
        }

        for (int i= 0 ;i<pos; i++){
            if(((1ll<<i)&prev)!=((1ll<<i)&best))
                ask(i+1,pos);
        }

        ans_best =nw_best ;
    }


}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}
