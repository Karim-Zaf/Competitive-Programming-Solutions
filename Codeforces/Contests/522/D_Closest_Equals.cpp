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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;
//#define int ll

const ll N = 5e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;


int n , q ,a [N];
map <int,int> last ;
vector<array<int,3>> Tree[4*N];

vector <array <int,3>> merge (vector <array <int,3>> a, vector <array <int,3>> b){
    vector <array <int,3>> ret ;
    int j= 0, i = 0;
    while (i<a.size() && j<b.size()){
        if (a[i][0]<b[j][0]) ret.pb(a[i++]);
        else ret.pb(b[j++]);
    }
    while (i< a.size()) ret .pb(a[i++]);
    while (j< b.size()) ret.pb(b[j++]);
    for (int i= ret.size()-2 ;i>=0 ;i--)
        ret[i][2] = min (ret[i][2],ret[i+1][2]);
    return ret ;
}

void build (int id = 0 ,int ns = 1 ,int ne = n){
    if (ns == ne ){
        int dist = (a[ns] ? ns - a[ns] : (int)(1e9));
        Tree[id].pb( {a[ns],dist,dist});
        return;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne -ns)/2 ;
    build(l , ns , md); build(r , md+1 , ne);
    Tree[id]=merge(Tree[l],Tree[r]);
}

int query(int qs , int qe , int id = 0,int ns = 1 , int ne = n){
    if (ns>qe || ne <qs ) return 1e9;
    if (qs <= ns && ne <= qe){
        array <int,3> p = {qs,0,0};
        int pos = lower_bound (all(Tree[id]),p) -Tree[id].begin();
        if (pos >= Tree[id].size()) return 1e9;
        else return Tree[id][pos][2];
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne -ns)/2 ;
    return min(query(qs,qe,l , ns ,md), query(qs, qe ,r, md+1 , ne));
}

void solve(){
    cin >> n >> q ;
    for (int i= 1 ;i<=n ;i++) cin >> a[i];
    for (int i= 1 ;i<=n ;i++){
        int x = a[i];
        a[i]= last[x];
        last[x]=i;
    }
    build();
    while (q--){
        int  l , r;
        cin >> l >> r;
        int curr = query(l,r);
        cout << (curr==1e9? -1:curr)<< endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--) solve();
}

// Failure gives you two choices: You stay down or You get up ;)
