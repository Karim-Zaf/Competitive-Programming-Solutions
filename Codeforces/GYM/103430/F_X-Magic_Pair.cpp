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
 
const int  N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;
 
void Solve(){
    int a , x, b ;
    cin >> a >> b >> x;
    if (a==x||b==x){cout << "YES" << endl;return;}
    if (a<b) swap (a,b);
//    int e =10000;
    while (true){
        if (a>=x && (a-x)%b==0){cout << "YES" << endl;return;}
        int f= abs(a-(a/b)*b);
//        cout << a << " " << b << " " << f<< endl;
        a=f;
        swap (a,b);
        if (b==0||a==0) break;
        if (a>=x && (a-x)%b==0){cout << "YES" << endl;return;}
    }
    cout << "NO" << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}