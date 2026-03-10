#include<bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;

#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

const ll mod = 1e9 + 7;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MAXII = 200005 ;

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}



void solve() {
    int l,w,n; cin>>l>>w>>n;
    if ((l*w)%n!=0){
        cout<<"IMPOSSIBLE";
        return;
    }
    char grid[101][101];
    int taille=(l*w)/n;
    if (l%taille==0){
        int cpt=0;
        int deb=65;
        for (int i=0; i<w; i++){
            for (int j=0; j<l; j++){
                grid[j][i]=(char)(deb);
//                cout<<(char)(deb);
                cpt++;
                if (cpt==taille){
                    deb++;
                    cpt=0;
                }
            }
        }
    }
    else if (w%taille==0){
        int cpt=0;
        int deb=65;
        for (int i=0; i<l; i++){
            for (int j=0; j<w; j++){
                grid[i][j]=(char)(deb);
//                cout<<(char)(deb);
                cpt++;
                if (cpt==taille){
                    deb++;
                    cpt=0;
                }
            }
        }
    }
    else{
        int deb=65;
        int a=gcd(l,taille);

        int b=taille/a;


        int maxiii=l/a;
        int maxiii2= w/b;
        for (int s=0; s<maxiii2; s++){
            for (int k=0; k<maxiii; k++){
                for (int i=0+k*a; i<a+k*a; i++){
                    for (int j=0+s*b; j<b+s*b; j++){
                        grid[i][j]=(char)(deb);
                    }
                }
                deb++;
            }
        }
    }


    for (int i=0; i<l; i++){
        for(int j=0; j<w; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc=1;
    //cin >> tc;
    while(tc--) {
        solve();
    }
}
