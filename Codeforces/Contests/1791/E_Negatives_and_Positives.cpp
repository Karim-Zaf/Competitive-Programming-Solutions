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

        ll n, sum=0 ,mn, neg=0; cin >> n;
        vi v(n);
        fr ( i,0, n ){
            cin >> v[i];
            if ( !i)mn =abs(v[i]);
            if ( v[i]<0)neg++;
            sum+=abs(v[i]);
            mn = min ( mn , abs(v[i]));
        }
if ( neg%2==0)cout << sum <<endl;
else cout<< sum -2*mn<<endl;
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
