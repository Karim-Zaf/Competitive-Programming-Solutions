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
int Tree[4*N];


void build (int id = 0 ,int ns = 1 ,int ne = n){
    if (ns == ne ){Tree[id]= a[ns];return;}
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne -ns)/2 ;
    build(l , ns , md); build(r , md+1 , ne);
    Tree[id]=__gcd(Tree[l],Tree[r]);
}

void update (int pos ,int val , int id = 0 ,int ns = 1 , int ne = n){
    if (pos > ne || pos <ns) return;
    if (ns == ne ) {Tree[id]=val ; return;}
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne -ns)/2 ;
    update(pos ,val,l , ns , md); update(pos ,val,r , md+1 , ne);
    Tree[id]=__gcd(Tree[l],Tree[r]);
}

int query(int qs , int qe , int x , int id = 0,int ns = 1 , int ne = n){
    if (ns>qe || ne <qs ) return 0;
    if (qs <= ns && ne <= qe && Tree[id]%x==0)return ne -ns +1;
    if (ns == ne) return 0;
    int l = 2*id +1 , r = 2*id +2 , md = ns + (ne -ns)/2 ;
    if (qs <= ns && ne <= qe && Tree[l]%x && Tree[r]%x)return 1e9;
    return query(qs,qe,x,l , ns ,md)+query(qs, qe ,x,r, md+1 , ne);
}

void solve(){
    cin >> n  ;
    for (int i= 1 ;i<=n ;i++) cin >> a[i];
    build();
    cin >> q;
    while (q--){
        int  x, l , r, pos;
        cin >> x;
        if (x==1){
            cin >> l >> r >> x;
            int ans = query(l,r,x);
            if (ans == r-l+1 || ans == r-l) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else {
            cin >> pos >> x ;
            update(pos ,x);
        }
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
