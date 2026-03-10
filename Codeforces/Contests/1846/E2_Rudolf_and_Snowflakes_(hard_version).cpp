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

const ll N = 1e4 + 8 , MOD =1e9+7, mod=1e18+7, INF = 1e18 ;

ll n;

__int128 verif (__int128 x , int puiss ){
    __int128 pow = 1 , sum = 1 ;
    for (int i= 0 ;i<puiss ;i++){
        pow*=x;
        sum+= pow;
        if (sum>n) return sum;
    }
    return sum ;
}

void solve(){
    cin >> n;
    for (int i =2 ; i<= 64 ;i++){
        ll l = 2 ,  r = n;
        while (l<=r){
            __int128 md = l + (r-l)/2;
            if (verif(md,i) == n ) {cout << "YES\n"; return;}
            if (verif(md,i) <n) l= md+1 ;
            else r = md-1;
        }
    }
    cout << "NO\n";
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}

// Failure gives you two choices: You stay down or You get up ;)