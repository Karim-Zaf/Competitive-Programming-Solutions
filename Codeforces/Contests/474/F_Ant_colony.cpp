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
#define int ll

const ll N = 1e5+5 , MOD =1e9+7, Q =2e5+3 ;
struct Node{int min =INF, gcd =INF , occ = INF;};

int a[N],n,q; Node Tree[4*N];

Node merge(Node a ,Node b){
    Node ret ;
    ret.min = min(a.min,b.min);
    if (a.min==b.min) ret.occ =min(INF, a.occ + b.occ) ;
    else if (a.min <b.min) ret.occ = a.occ;
    else ret.occ = b.occ;
    if (a.gcd == INF) ret.gcd = b.gcd;
    else if (b.gcd == INF) ret.gcd = a.gcd;
    else ret.gcd = __gcd (a.gcd,b.gcd);
    return ret ;
}

void build( int id=0 , int ns = 0 , int ne = n-1){
    if (ns == ne) {
        Tree[id] = {a[ns], a[ns], 1};
        return;
    }
    int l  = 2*id +1 , r = 2*id +2, md = ns + (ne-ns)/2 ;
    build (l , ns ,md);build(r,md+1,ne);
    Tree[id]= merge(Tree[l],Tree[r]);
}

Node query(int qs , int qe , int id = 0 , int ns = 0 , int ne = n-1 ){
    Node rien ;
    if (ne<qs || ns>qe) return rien;
    if (qs <=ns && ne<= qe)
        return Tree[id];
    int l  = 2*id +1 , r = 2*id +2, md = ns + (ne-ns)/2 ;
    return merge(query(qs,qe,l,ns,md), query(qs,qe,r,md+1,ne));
}

void solve (){
    cin >> n ;
    for (int i= 0 ;i<n ; i++) cin >> a[i];
    build ();
    cin >> q ;
    while (q--){
        int l, r;
        cin >> l >> r;
        Node curr = query(--l,--r);
        if (curr.min == curr .gcd)
            cout << r-l+1 - curr.occ << endl;
        else cout << r-l+1  << endl;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
//    cin >> test_case ;
    while (test_case--) solve();
}