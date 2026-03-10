/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#pragma GCC optimize(" unroll-loops")
#pragma Gcc optimize("Ofast")
#pragma GCC optimize("O3")
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

const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;

int Tree[4*N][101];
int n ,q, upd[4*N] , indx[N];

void unlazy(int id, int ns , int ne ){
    if (upd[id]==0|| ns==ne) return;
    int l = 2*id +1 , r = 2*id +2 ;
    for (int i = 0; i<=100 ; i++) Tree[l][i]= Tree[id][Tree[l][i]];
    for (int i = 0; i<=100 ; i++) Tree[r][i]= Tree[id][Tree[r][i]];
    upd[l]= upd[r]=1 ;
    upd[id]=0 ;
    for (int i = 0; i<=100 ; i++) Tree[id][i]=i;
}

void update (int qs, int qe , int x , int y , int id= 0 ,int ns = 0, int ne = n-1){
    if (ns>qe || ne<qs) return;
    unlazy(id, ns,ne) ;
    if (qs <= ns && ne <= qe){
        for (int i= 0 ; i<= 100 ; i++) if (Tree[id][i] == x) Tree[id][i]=y;
        upd[id]=1 ;
        return;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe , x, y , l ,ns , md);
    update (qs , qe , x, y , r ,md+1 , ne);
}

void get (int ns =0 , int ne = n-1, int id = 0 ){
    unlazy(id, ns,ne) ;
    if (ns == ne) { indx [ns]= id ; return; }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    get( ns, md, l);get( md+1, ne, r);
}

void solve() {
    cin >> n ;
    for (int i= 0 ; i<4*N ; i++)
        for (int j= 0; j<=100 ; j++)Tree[i][j]=j;
    vector <int> v(n) ;
    for (auto &x : v) cin >> x ;
    cin >> q ;
    while (q--){
        int l , r ,x , y ;
        cin >> l >> r >> x >> y ;
        update(--l , --r , x , y) ;
    }
    get();
    for (int i= 0 ;i< n; i++) v[i]= Tree[indx[i]][v[i]];
    for (auto x : v) cout << x << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}