    //  (1/0+) WINS
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
    #define watch(x) cout << (#x) << " is " << (x) << endl;
    #define F first
    #define S second
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define endl '\n'
    #define INF (ll)(1e18)
    void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
    void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
    void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
    void dbgmp(map<ll,ll> mp){for(auto p: mp) cout<<p.F<<" "<<p.S<<endl;}
    void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}

    const ll N = 1e5+7 , mod =1e9+7, Q =1e5+3 ;
    vector<ll> graph[N];
    bool visited[N];
    ll dist[N], mx = 1 ;

    ll dp[N];

    void solve(){
        ll q , d =-INF, type, a, b ,n, ok =0  , mn,mx ; 
        cin >> q ;
        vi res ;
        while ( q--){
            cin >> type;
            if (type == 1 && !ok ){
                cin >> a >> b >> n ;
                res.pb(1);
                mn = (a-b)*(n-1) +b +1;
                if (n == 1 ) {
                    mn = - 1 ; 
                    mx = a;
                }
                mx = (a-b)*(n-1) +a;
                ok =1 ; 
            }
            else if ( type == 1 ){
                cin >> a >> b >> n ;
                ll nw_mn = (a-b)*(n-1)+b+1;
                ll nw_mx = (a-b)*(n-1) +a;
                if ( n==1 ){
                    nw_mn= -1  ;    
                    nw_mx==a;
                }
                if (nw_mn<=mx && nw_mx>=mn ){
                    res.pb(1);
                    mn = max( nw_mn , mn);
                    mx = min( nw_mx , mx);
                }
                else res.pb(0);
            }
            else if (!ok) {
                cin >> a >> b ; 
                res.pb(-1);
            }
            else{
                cin >> a >> b ; 
                ll nnn = (mn-b-1)/(a-b)+1;
                ll n2 = (mx-b-1)/(a-b)+1;
                nnn = max (1ll,nnn);
                n2 = max (1ll,n2);
                if (nnn==n2)
                   res.pb(nnn);
                else res.pb(-1);
            }
        }
        dbg(res);
    }

    int main(){
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
        #endif
        FAST ;
        io() ;
        srand(time(0)) ;
        ll tt=1;
        cin >> tt;
        while (tt--)
            solve() ;
    }
