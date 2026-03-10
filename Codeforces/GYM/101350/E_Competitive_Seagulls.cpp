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
const ll MAXII = 10000005 ;

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


vector<ll>sie;

void sieve(){
    bool visited[MAXII];
    memset(visited, 0, sizeof(visited));
    for (int i=2; i<=10000000; i++){
        if (!visited[i]){
            sie.pb(i);
            for (int j=i+i; j<=10000000;  j+=i)
                visited[j]=1;
        }
    }
}


void solve() {
//    int tab[MAXII];
    ll L; cin>>L;
//    for (int i=0; i<=L; i++)
//        tab[i] = '0';
    if (L==1){
        cout<<"first"<<"\n";
        return;
    }
    if (L==2){
        cout<<"second"<<"\n";
        return;
    }

    if (L==3){
        cout<<"second"<<"\n";
        return;
    }

    if (L==4){
        cout<<"first"<<"\n";
        return;
    }

    if (L==5){
        cout<<"first"<<"\n";
        return;
    }

    if (L==6){
        cout<<"first"<<"\n";
        return;
    }

    cout<<"first"<<"\n";


//    ll restant = L;
//    ll blocs=0;
//    ll maxii = (L/2);
//    if (L%2==1)
//        maxii++;
//
//    ll pos = lower_bound(all(sie), maxii) - sie.begin();
//    if (pos==sz(sie))
//        pos--;
//    if (sie[pos] > maxii)
//        pos--;
//
//    for (int i=pos; i>=0; i--){
//        ll nbr = restant / (sie[pos]+1);
//        blocs += nbr;
//        restant -= (nbr * (sie[pos]+1));
//        if (restant==0)
//            break;
//        if (restant==1){
//            blocs++;
//            break;
//        }
//    }
//    if (blocs%2==1)
//        cout<<"second"<<"\n";
//
//    else
//        cout<<"first"<<"\n";

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //sieve();
//    cout<<sz(sie);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
}
