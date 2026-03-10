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

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

vector<int> digit ;

int power ( int x, int y ){
    int ret = 1 ;
    while(y--) ret *= x ;
    return ret ;
}

void work (int k , int sz ) {
    if (sz >=11) return;
    int sum = 0, other = k ;
    while (other){
        sum += other%10;
        other /= 10 ;
    }
    if (sum>10)return;
    if (sum == 10 ) {digit.pb(k);return;}
    for (int i= 0; i<=9 ; i++){
        work( i *power(10,sz) + k , sz +1);
    }
}

int mp[N] ;
void Solve(){
    for (int i= 0 ; i<= 9 ;i++) work (i,1);
    int n ; cin >> n ;
    sort(all(digit));
    cout << digit[n-1] << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}