//  (1/0+) WINS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;} 
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

const ll N = 1e5+2 , MOD =1e9+7, Q =2e5+3 ;
 
ll a[N];
ll n,q,l,t,r;
ll tree[4*N];
 
int mrg(int x, int y){
    return max(x,y);
}
 
void build(int id=0,int ns = 0, int ne = n-1){
    if(ns==ne){
        tree[id] = a[ns];
        return ;
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id] = mrg(tree[l],tree[r]);
}
 
 
int query(int qs, int qe, int id=0, int ns=0, int ne=n-1){
    if(ns>qe || qs>ne){
        return -1e7; ///infnity
    }
    if(qs<=ns && qe>=ne){
        return tree[id];
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    return mrg(query(qs, qe, l, ns, md), query(qs, qe,r, md+1,ne));
}

void solve(){ 
    cin >> n; 
    vi v(n ) , ans (n);
    map <ll,ll> pos, pos2 ;
    multiset <ll> s ; 
    for (ll i= 0 ;i<n  ; i++) {  cin >> v[i] ; s.insert( v[i] ); pos[v[i]]=i; }
        auto it = s.begin() ; 
    for (ll i= 0 ;i<n  ; i++) {
        a[i]= pos[(*it)];
        pos2[a[i]]= i ; 
            it++; 
    }
    build () ; 
    for (ll i = 0 ;i<n ; i++ ){
        auto it = s.lower_bound(v[i]) , b = s.begin();
        it -- , b--; 
        if  (it == b)ans[i]=-1; 
        else {
            ll now = pos2[pos[*it]] ;
            ll j= query(0,now) ;
            if (j<i) ans[i]=-1 ;
            else ans[i]= j - i -1 ;
        }
    }
    dbg(ans);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;    
    // cin >> test_case ;   
    while (test_case--)  solve() ;
}