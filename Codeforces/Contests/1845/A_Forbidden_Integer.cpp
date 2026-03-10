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

const ll N = 3e5+ 7 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){
    int n , k , x ;
    cin >> n>> k >> x; 
    if (x!=1 ) {
        cout << "YES\n" ;
        cout << n << endl;
        for (int i= 1 ;i<= n ;i++)
            cout << 1 << " "; cout << endl;
        return;
    }
    if (k==1 && x==1){
        cout << "NO\n";
        return;
    }
    if (k==2 && n%2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n" ;
    if (n%2==0){
        cout << n /2<< endl;
        for (int i = 0 ; i<n/2;i++)
            cout << 2 << " " ; cout << endl;
        return;
    }
    cout << n /2 << endl;
    for (int i= 0 ; i< n/2 -1 ; i++){
        cout << 2 << " ";
    }
    cout << 3 << " ";
    cout << endl;
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