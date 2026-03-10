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

const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;

struct DSU{
    vector<int>  sz , parent ; 
    void init(int n){ for (int i = 0; i < n; i++){ parent.pb(i) ; sz.pb(1) ; } }
    int get(int a){return (parent[a] == a ? a : parent[a] = get(parent[a]));}
    bool unite(int a, int b){
        if ((a = get(a))==(b = get(b))) return false;
        if (sz[a]>sz[b]) swap (a,b) ; 
        parent[b] = a;
        sz[a] += sz[b]; 
        return true ; 
    }
    bool same_set(int a, int b){return get(a) == get(b);}
    int size(int a){ return sz[get(a)];}
};

void solve (){
    int n , q ; 
    cin >> n >> q ; 
    DSU ds ;
    ds.init(n+1);  
    map <int , vector <pair<int,int>>> mp ; 
    vector <int> Qry (q);
    for (int i= 0 ; i<n-1 ; i++ ){
        int l , r , x ; 
        cin >> l >> r >> x;
        mp[x].pb(make_pair (l,r));
    }
    long long res = 0 ,  mx = 1 ; 
    for (int i= 0 ;i< q ; i++){
        cin >> Qry[i];
        mx = max <int long long >(mx, Qry[i]);
    }

    function <ll(ll)> hesba =[](ll a){
        return (a*(a-1))/2 ;
    };

    vector <long long> ans (mx+1) ;
    for (int i= 1 ;i<= mx;i++){
        for (auto x : mp[i]){
            res -= hesba (ds.size(x.F));
            res -= hesba (ds.size(x.S));
            ds.unite (x.F,x.S);
            res += hesba(ds.size(x.F));
        }
        ans[i]= res ;
    }

    for (int i= 0 ;i< q ; i++)
        cout << ans[Qry[i]] << " " ; cout << endl; 
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}