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

const ll N =100+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

bool verif (vector <int>& v){
    if (v[0]==v[2] && v[2]==v[4] && v[1]+v[3]+v[5]==v[2]) return true ;
    if (v[0]==v[2] && v[1]+v[3]==v[5] && v[2]+v[4]==v[5]) return true ;
    if (v[0]==v[4] && v[1]+v[5]==v[3] && v[2]+v[0]==v[3]) return true ;
    if (v[2]==v[4] && v[3]+v[5]==v[1] && v[2]+v[0]==v[1]) return true ;
    return false ;
}

void solve(){
    vector <int> v(6) ;
    for (int i= 0; i<6 ; i++) cin >> v[i] ;

    for (int i= 0 ; i<8 ; i++){
        vector <int> curr = v ;
        for (int j= 0; j<3 ; j++){
            if (i&(1<<j))
                swap (curr[2*j], curr[2*j+1]);
        }
        if (verif(curr)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n" ;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}