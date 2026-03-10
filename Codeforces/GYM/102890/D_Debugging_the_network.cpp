
#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;

#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(x) (int((x).size()))

const ll mod = 1e9 + 7;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MAXII = 100005 ;

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}


string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

ll convert(string ch){

    ll ans = 0;
    ll deb = 0;
    for (int i=sz(ch)-1; i>=0; i--){
        ll coef = pow(10,deb);
        ans = ans + (ch[i]-'0') * coef;
        deb++;
    }

    return ans;
}


void solve() {
    string ch; ll K;
    cin>>ch>>K;
    ll ans = 0;
    string now="";
    ll deb = -1;
    ll sum = 0;
    string finall="";
    while(deb<sz(ch)){
        deb++;
        if (deb==sz(ch))
            break;
        if (ch[deb]>='0' && ch[deb]<='9')
            now = now + ch[deb];

        else{
            if (now==""){
                finall = finall + ch[deb];
                sum++;
                continue;
            }

            if (sz(now)>7){
                cout<<"unfeasible"<<"\n";
                return;
            }
            ll ans = convert(now);
            sum+=ans;
            if (sum>K){
                cout<<"unfeasible"<<"\n";
                return;
            }
            for (int i=0; i<ans;i++){
                finall = finall + ch[deb];
            }
            now="";
        }
    }

    if (sum>K){
        cout<<"unfeasible"<<"\n";
        return;
    }
    cout<<finall<<"\n";


}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
}
