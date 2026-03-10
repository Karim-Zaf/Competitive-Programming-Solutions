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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

int Tree[4*N] , upd[4*N], lazy[4*N],n;

void unlazy(int id){
    if (upd[id]==0) return;
    int l = 2*id +1 , r = 2*id +2 ;
    Tree[id]+=lazy[id];
    upd[l]= upd[r]= 1,upd[id]=0;
    lazy[l]+=lazy[id];
    lazy[r]+= lazy[id];
    lazy[id]=0 ;
}


void update (int qs , int qe , int val , int ns=1 , int ne=n , int id =0){
    unlazy(id);
    if (qs >ne|| qe <ns) return ;
    if (qs <= ns && ne <= qe ){
        upd[id]=1;
        lazy[id]=val;
        unlazy(id);
        return ;
    }
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    update (qs , qe , val , ns , md, l);
    update (qs ,qe, val , md+1 , ne ,r);
    Tree[id]=min(Tree[l],Tree[r]);
}

int query (int qs , int qe , int ns=1 , int ne=n , int id =0){
    unlazy(id);
    if (qs >ne|| qe <ns) return INF ;
    if (qs <= ns && ne <= qe )return Tree[id] ;
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne-ns)/2 ;
    return min(query (qs , qe , ns , md, l) ,query (qs ,qe, md+1 , ne ,r));
}

vector<int> conv (string s){
    vector<int> v;
    string lst="";
    for (auto x: s) {
        if (x==' ') v.pb(stoll(lst)),lst="";
        else lst+= x;
    }
    v.pb(stoll(lst));
    return v;
}

void Solve() {
    cin >> n;
    for (int i= 1,x; i<=n;i++){
        cin >> x;
        update (i,i,x);
    }

    int q ; string s;
    cin >> q;
    getline(cin,s);
    while(q--){
        getline(cin,s);
            vector<int> v=conv(s);
        int l , r ;
        l = v[0]+1,r=v[1]+1;
        if (v.size()==3 && l<=r) update(l,r,v[2]);
        else if (v.size()==3) update(1,r,v[2]),update(l,n,v[2]);
        else if (l<=r) cout << query(l,r) << endl;
        else cout << min(query(l,n),query(1,r))<<endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}