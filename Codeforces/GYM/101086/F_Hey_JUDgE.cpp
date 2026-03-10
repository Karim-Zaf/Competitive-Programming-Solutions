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
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}



void solve() {
    string ch; cin>>ch;
    int cpt[10]={0};
    set<char>s;
    for (int i=0; i<7;i++){
        s.insert(ch[i]);
        cpt[ch[i]-'A']++;
    }
    if (s.size()==5){
        yes;
        return;
    }
/////
//    for (int i=0; i<6;i++)
//        cout<<cpt[i]<<" ";///
//    cout<<endl;

    vector<int>v;
    vector<int>missing;
    int inventory[10];
    for (int i=0; i<5; i++){
        inventory[i]=max(0,cpt[i]-1);
        if (cpt[i]==0)
            missing.pb(i+1);
    }
///
//    dbg(missing);
//    sort(all(missing));
//    for (int i=0; i<5; i++)
//        cout<<inventory[i]<<" ";


    for (int i=0; i<missing.size();i++){
        if (missing[i]==1){
            no;
            return;
        }
        else if (missing[i]==2){
            if (inventory[0]>=2){
                inventory[0]-=2;
            }
            else{
                no;
                return;
            }
        }

        else if (missing[i]==3){
            if (inventory[1]>=1 && inventory[0]>=1){
                inventory[1]--;
                inventory[0]--;
            }
            else if  (inventory[0]>=3){
                inventory[0]-=3;
            }

            else{
                no;
                return;
            }
        }
        else if (missing[i]==4){
            if (inventory[2]>=1 && inventory[0]>=1){
                inventory[0]--;
                inventory[2]--;
            }
            else if  (inventory[1]>=2){
                inventory[1]-=2;
            }
            else if (inventory[0]>=2 && inventory[1]>=1){
                inventory[0]-=2;
                inventory[1]--;
            }

            else if (inventory[0]>=4){
                inventory[0]-=4;
            }
            else{
                no;
                return;
            }
        }
        else if (missing[i]==5){
            if (inventory[3]>=1 && inventory[0]>=1){
                inventory[3]--;
                inventory[0]--;
            }
            else if (inventory[2]>=1 && inventory[1]>=1){
                 inventory[2]--;
                inventory[1]--;
            }
            else if (inventory[1]>=2 && inventory[0]>=1){
                inventory[1]-=2;
                inventory[0]--;
            }

            else if (inventory[0]>=3 && inventory[1]>=1){
                inventory[0]-=3;
                inventory[1]--;
            }

            else if (inventory[0]>=2 && inventory[2]>=1){
                inventory[0]-=2;
                inventory[2]--;
            }

            else if (inventory[0]>=5)
                inventory[0]-=5;
            else{
                no;
                return;
            }
        }
    }
    yes;


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
