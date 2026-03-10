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
const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){
    int n , m , h ;
    cin >> n >> m >> h ;
    vector< array <int,3>> p(n);
    vector <vector <int>> v(n), a(n);
    for (int i= 0 ; i<n ;i++){
        for (int j= 0; j<m ; j++){
            int x ;
            cin >> x ;
            a[i].pb(x);
            v[i].pb(x);
        }
    }
    for (int i= 0 ; i<n ;i++){
        sort (all(v[i]));
        sort (all(a[i]));
    }
    for (int i= 0 ; i<n ;i++) {
        for (int j = 1 ;  j <m ; j++)
            a[i][j]+=a[i][j-1];
        for (int j = 1 ;  j <m ; j++)
            v[i][j]+=v[i][j-1];
        for (int j = 1 ;  j <m ; j++)
            v[i][j]+=v[i][j-1];
        p[i][2] = i;
        for (int j = 0; j<m ;j++){
            if (a[i][j]<=h) {
                p[i][0]++;
                p[i][1]= v[i][j];
            }
        }
    }
//    for (int i= 0 ; i<n ;i++) {
//        kar (v[i]);
//    }
    sort(all(p),[](array <int,3> a,array <int,3> b){
        if (a[0]> b[0] ) return true;
        if (a[0]== b[0] && a[1] < b[1]) return true ;
        if (a[0]== b[0] && a[1] == b[1] && a[2]<b[2]) return true ;
        return false ;
    });

    for (int i= 0;i<n ;i++){
        if (p[i][2]==0) {
            cout << i + 1 << endl;
        }
    }

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