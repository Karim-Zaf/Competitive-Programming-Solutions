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
        ll n , c ,sum=0 , res =0 ; 
        cin >> n >> c ;
        vi v (n), pref (n);
        fr ( i, 0 , n){
            cin >> v[i];
            v[i]=v[i]+i+1;
        }
        ll i =1 ;
        sort (all (v));
        pref[0]=v[0];
        fr ( i ,1, n)
            pref [i]=pref[i-1]+v[i];
        // dbg (pref);
        ll pos = upper_bound (all(pref), c)-pref.begin();
        // watch(pos);
        if (pos >=n )
            if (pref[pos-1]<=c &&   pos>=1)
                cout << pos<< endl; 
            else
                cout << 0 <<endl;
        else cout << pos<< endl; 

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
