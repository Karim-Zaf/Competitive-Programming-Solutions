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

const int  N=2e5+8,MOD=1e9+7,mod=1e1+7,INF=0;

int n , q ;
set <int> Tree[4*N] ;


void update(int pos , int val, int id = 0 , int ns = 1, int ne=n){
    if (pos <ns|| pos >ne)return;
    Tree[id].insert(val);
    if (ns==ne) return;
    int l = 2*id+1, r = 2*id+2, md = ns + (ne-ns)/2 ;
    update (pos,val, l,ns,md);
    update (pos,val, r,md+1,ne);
}

bool query(int l1 , int r1, int l2, int r2 ,int id=0 ,int ns = 1 , int ne =n){
    if (ns>r1|| ne<l1) return false ;
    if (l1<=ns && ne<=r1){
        auto it = Tree[id].lower_bound(l2);
        if (it==Tree[id].end())return false ;
        if ((*it)<=r2)return true; return false ;
    }
    int l = 2*id+1, r = 2*id+2, md = ns + (ne-ns)/2 ;
    return query(l1,r1,l2,r2,l,ns,md)||query(l1,r1,l2,r2,r,md+1,ne);
}



void Solve(){
    cin >> n>> q ;
    set <int> s;
    for (int i= 1;i<=n ;i++) s.insert(i);
    vector<array<int, 4>> qry;
    bool ok = false;
    for (int i = 0; i < q; i++){
        int x;
        cin >> x;
        if (x){
            int y;
            cin >> y;
            qry.push_back({x, y, 0, 0});
            ok = true;
        }
        else{
            int l, r, ind;
            cin >> l >> r >> ind;
            qry.push_back({x, l, r, ind});
        }
    }
    if (!ok) return;
    for (auto [x, l, r, ind] : qry){
        if (x){
            int y = l;
            if (s.find(y)==s.end()){cout <<"NO\n";continue;}
            auto it = s.find(y);
            int l , r ;
            if (it!=s.begin()) l=*prev(it)+1;
            else l = 1;
            if (next(it)!=s.end()) r =*next(it)-1;
            else r = n ;
            if (query(l,y,y,r))cout << "YES\n";
            else cout <<"N/A"<< endl;
            continue;
        }
        if (ind==1) {
            update(l,r);
            continue;
        }
        auto it= s.lower_bound(l);
        vector <int> erase;
        while (it!=s.end()&& (*it)<=r){
            erase.pb(*it);
            it++;
        }for (auto e: erase)s.erase(e);
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}