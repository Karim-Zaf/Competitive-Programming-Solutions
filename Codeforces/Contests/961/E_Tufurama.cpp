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
#define endl '\n'
#define int ll


const long long N=2e5+8,MOD=1e9+7,mod=1e9+7,INF=1e18;

int n , v[N] ;
vector <int> Tree[4*N];

void Merge (int l ,int r , int id){
    int one =0 , two = 0 ;
    while (one <Tree[l].size() && two<Tree[r].size()){
        if (Tree[l][one]<=Tree[r][two]) Tree[id].pb(Tree[l][one++]);
        else Tree[id].pb(Tree[r][two++]);
    }
    while (one<Tree[l].size())Tree[id].pb(Tree[l][one++]);
    while (two<Tree[r].size())Tree[id].pb(Tree[r][two++]);
}

int Query (int qs , int qe , int val, int id= 0 , int ns = 1 ,int ne =n){
    if (ns> qe|| ne<qs) return 0;
    if (qs <= ns && ne <= qe) {
        int Pos= lower_bound(all(Tree[id]),val)-Tree[id].begin();
        return Tree[id].size()-Pos;
    }
    int l = 2*id+1 , r = 2*id +2 , md = ns + (ne-ns)/2;
    return Query(qs,qe,val,l,ns,md)+Query(qs,qe,val,r,md+1,ne);
}

void Build(int id=0 , int ns = 1 , int ne =n){
    if (ns==ne) {Tree[id].pb(v[ns]);return;}
    int l = 2*id+1 , r = 2*id +2 , md = ns + (ne-ns)/2;
    Build(l,ns,md); Build(r , md+1 , ne);
    Merge (l ,r, id);
}

void Solve(){
    cin >> n ;
    int res = 0;
    for (int i= 1; i<= n; i++) cin >> v[i] ;
    Build();
    for (int i= 1; i<=n ; i++ ){
        int l =i+1 , r= min(v[i],n);
        if (l>r) continue;
        res += Query(l,r,i);
    }
    cout << res << endl;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}