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
    int x=0, res=0,y=0,n;  
    cin>> n; 
    string z ; cin >> z;
    x =n-1 ; y=0;
    while ( x>y){
        if (z[x]=='0'&& z [y]=='1' || z[x]=='1'&& z [y]=='0'){
            x--; y++; res+=2;
        }
        else break;
    }
    cout << n -res <<endl;
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
