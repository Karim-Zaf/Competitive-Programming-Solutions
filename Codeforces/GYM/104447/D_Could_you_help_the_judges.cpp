#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}

vector<int> v[12] ;

struct trie{

    int sub = 0 ;
    trie* children[2] ;
    void init(){
        sub = 0 ;
        children[0] = children[1] = NULL ;
    }
    struct trie *getNode(void)
    {
        struct trie *pNode =  new trie;
        for (int i = 0; i < 2; i++)
            pNode->children[i] = NULL;
        return pNode;
    }
    void insert(int x , int j = 10)
    {
        if(j==-1){
            sub = 1 ;
            return ;
        }

        int c = (x>>j)&1 ;
        if(children[c]==NULL) children[c] = getNode() ;
        if(children[!c]==NULL) children[!c] = getNode() ;
        children[c]->insert(x , j-1) ;
        sub = children[0]->sub + children[1]->sub ;
    }
    int query(int x , int j = 10)
    {
        if(j==-1) return 0 ;
        int c = (x>>j) & 1 ;
        if(children[c]==NULL) children[c] = getNode() ;
        if(children[!c]==NULL) children[!c] = getNode() ;
        if(children[!c]->sub>0) return (1<<j) + children[!c]->query(x , j-1) ;
        return children[c]->query(x , j-1) ;
    }

};

const int N = 1e5+5 ;
int a[N] ;
int p[N] ;

void solve() {
    int n , k ;
    cin>>n>>k ;
    trie root ;
    root.init() ;
    int ans = 0 ;
    root.insert(0) ;
    vector<int> pos(10000 , -1) ;
    for(int i =1 ; i<=n ; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        pos[a[i]] = i ;
    }
    for(int i =1 ; i<=n ; i++){
        
        p[i] = a[i] ;
        if(pos[p[i]]!=i) continue;
        ans = max(ans , root.query(p[i])) ;
        root.insert(p[i] , 10) ;
        for(int j : v[k]){
            ans = max(ans , root.query(p[i] ^ j)) ;
        }
    }
    cout<<ans<<endl;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    for(int i = 0 ; i<1024 ; i++){
        int j = __builtin_popcount(i) ;
        v[j].pb(i) ;
    }

    ll tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}