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

int bit (int x , int b){
    if ((1ll<<b) &x) return 1 ;
    return 0 ;
}

int work(int a, int b , int r ){
    int curr = 0 , flag = 0;
    for (int i= 62 ;i>=0; i--){
        if (!bit(a,i) && bit(b,i) && (curr+(1ll<<i))<=r && !flag){
            curr+=(1ll<<i);
            a+= (1ll<<i) ;
            b-= (1ll<<i) ;
        }
        else if (bit(a,i) && !bit(b,i) && (curr+(1ll<<i))<=r && flag){
            curr+=(1ll<<i);
            a-= (1ll<<i) ;
            b+= (1ll<<i) ;
        }
        if (bit(a,i)&&!bit(b,i)) flag=1 ;
    }
    return abs(a-b);
}

void Solve() {
    int a , b , r ;
    cin >> a >> b >> r ;
    cout << min ({abs(a-b),work(a,b,r),work(b,a,r)})<<endl;

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case;
    while (Test_case--) Solve();
}