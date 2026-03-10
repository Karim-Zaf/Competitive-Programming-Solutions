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

    const ll N = 1e5+3;

    vector <ll> vv, primes;
    // map <ll,ll> mp;
    set <ll> ss;
    ll x;

    void solve(){ 
        ll n,res=0 ; cin >> n ;
        map <char,ll> mp;
        vi dif ( n,0), teli(n,0);
        string x ; cin >> x ;
        dif [0]={1};
        teli [0]={1};
        mp[x[0]]++;
        fr (i, 1, n){
            char e = x[i];
            if (!mp[e]&&i)
                dif[i]=dif[i-1]+1;
            else 
                dif[i]=dif[i-1];
             mp[e]++;
        }         
        mp.clear();
        mp[x[n-1]]++;
        rfr(i, n-2, -1){
            char e = x[i];
            if (!mp[e])
                teli[n-1-i]=teli[n-2-i]+1;
            else {
                teli[n-1-i]=teli[n-2-i];
            
            // watch (i);
                // if (!i)watch(teli [n-1-i]);
        }
             mp[e]++;
        }
        // dbg ( dif );
        // dbg ( teli);
        fr (i, 0, n-1){
        res=max(res, teli[i]+dif[n-2-i] ) ;
        // watch (i);
        // watch (n-2-i);
     }
    cout << res << endl;

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
         cin >> tt;
         while (tt--)
              solve() ;
    }
