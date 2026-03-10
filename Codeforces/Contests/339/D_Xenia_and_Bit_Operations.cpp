#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define INF (ll)(1e18)
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}
 
const ll N = 1e6+3, mod= 1e9 +7,N_max = 1<< 17 +5;
vi v;
ll x, n, val, p  ;
ll tree [4*N_max];

ll merge(ll x, ll y , ll degre){
    if ( degre %2 && p%2==0 || degre%2==0 && p%2)
        return x^y;
    else 
        return x|y;
}
void build ( ll id =0 ,ll ns =0 , ll ne = n-1, ll degre=1){
    if ( ns== ne){
        tree [id]=v[ns];
        return;
    }
    ll mid = ns + (ne-ns)/2; 
    ll l = 2*id +1;
    ll r = 2*id +2;
    build (l,ns,mid,degre+1);
    build (r, mid+1,ne,degre+1);
    tree[id]=merge(tree[l],tree[r],degre);
}


void update ( ll pos , ll val , ll id =0 ,ll ns =0 , ll ne=n-1, ll degre=1){
    if ( pos <ns || pos > ne)
        return;
    if  ( ns == ne ){
        tree[id]= val; 
        return;
    }
    ll mid = ns + (ne-ns)/2;
    ll l = 2*id +1;
    ll r = 2*id +2;
    update (pos, val , l, ns, mid,degre+1);
    update (pos, val , r, mid +1, ne, degre+1);
    tree [id]= merge ( tree[l], tree [r],degre);
}

void solve(){
    ll q ,xx ; 
    cin >> p  >>q;
    n=1<<p;
    for ( ll i = 0 ; i< n ; i++){
        cin >> xx ;
        v.pb( xx );
    }
    build ();
    // for (ll i =0 ; i<2*n-1 ; i++)cout << tree[i]<< " " ; cout <<endl;
    
    while ( q-- ){
        ll pos , val  ;
        cin >> pos >> val;
        update (--pos , val );
        // for (ll i =0 ; i<2*n-1 ; i++)cout << tree[i]<< " " ; cout <<endl;
        cout << tree [0]<<endl;
    }

}
int main()
{
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
     #endif
     FAST ;
     io() ;
     srand(time(0)) ;
     ll tt=1;
     // cin >> tt;
     while (tt--)
          solve() ;
}