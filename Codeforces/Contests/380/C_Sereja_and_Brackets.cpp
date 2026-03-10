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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

struct Node {int open =0, closed =0, valid = 0;};

const ll N = 1e6+5 , MOD =1e9+7, Q =2e5+3 ;
string ch ;
Node Tree[4*N];
int q , n ;

Node merge (Node a ,Node b){
    Node ret ;
    ret.valid = a.valid + b.valid;
    int tankis = min (a.open , b.closed);
    ret.valid += tankis*2;
    ret.open = a.open + b.open -tankis;
    ret.closed = a.closed + b.closed -tankis;
    return ret;
}

void build (int id = 0, int ns = 0 , int ne = n-1){
    if (ns==ne){
        Tree[id].open += (ch[ns]=='(');
        Tree[id].closed += (ch[ns]==')');
        return;
    }
    int l = 2*id +1 , r = 2*id +2 ,md = ns + (ne-ns)/2 ;
    build(l ,ns, md);
    build(r, md+1, ne);
    Tree[id]= merge (Tree[l],Tree[r]);
}

Node query (int qs , int qe , int id = 0, int ns = 0 , int ne = n-1){
    Node rien={0,0,0};
    if (qe<ns || qs> ne) return rien;
    if (qs<=ns && ne<= qe) return Tree[id];
    int l = 2*id +1 , r = 2*id +2 ,md = ns + (ne-ns)/2 ;
    return merge (query(qs,qe,l,ns,md) , query(qs,qe,r, md+1,ne));
}

void solve (){
    cin >> ch >> q ;
    n = ch.size();
    build();
    while(q--){
        int l , r ;
        cin >> l>> r ;
        cout << query(--l,--r).valid <<endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
//    cin >> test_case ;
    while (test_case--) solve();
}