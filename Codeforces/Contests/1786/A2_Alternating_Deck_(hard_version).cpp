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
 
const ll N = 1e5+3, mod= 1e9 +7;
 
vector <ll> vv, primes;
// map <ll,ll> mp;
set <ll> ss;
ll x;
    
void solve(){
    ll n ,a=1, b=0, blacka =1, whitea =0  , blackb=0, whiteb=0;
    cin >> n;
    vi v ( n );
    ll i =2,j=1;
    while ( j<=n){
        if (j+i<=n){
            if ((j+1)%2!=0 && i%2){
                blackb+= i/2+1;
                whiteb+=i- i/2-1;
            }
            else {
                blackb+= i/2 ;
                whiteb+= i -(i/2);
            }
            b+=i;
            j+=i;
            i++;
          //    watch (i);
        }
        else {b+=n-j;
        if ((j+1)%2!=0 && (n-j)%2){
                blackb+= (n-j)/2+1;
                whiteb+=(n-j)- (n-j)/2-1;
            }
            else {
                blackb+= (n-j)/2;
                whiteb+= (n-j) -((n-j)/2);
            }
           break;}
         if (j+i<=n){
           if ((j+1)%2!=0 && i%2){
                blackb+= i/2+1;
                whiteb+=i- i/2-1;
            }
            else {
                blackb+= i/2 ;
                whiteb+= i -(i/2);
            }
            b+=i;
            j+=i;
            i++;
          //    watch (i);
        }
        else {b+=n-j;
        
              if ((j+1)%2!=0 && (n-j)%2){
                blackb+= (n-j)/2+1;
                whiteb+=(n-j)- (n-j)/2-1;
            }
            else {
                blackb+= (n-j)/2;
                whiteb+= (n-j) -((n-j)/2);
            }
           break;}
        if ( j+i<=n){
             if ((j+1)%2!=0 && i%2){
                blacka+= i/2+1;
                whitea+=i- i/2-1;
            }
            else {
                blacka+= i/2 ;
                whitea+= i -(i/2);
            }
            a+=i;
           j+=i;
           i++;
          //    watch (i);
        }
        else {a+=n-j;
        
               if ((j+1)%2!=0 && (n-j)%2){
                blacka+= (n-j)/2+1;
                whitea+=(n-j)- (n-j)/2-1;
            }
            else {
                blacka+= (n-j)/2;
                whitea+= (n-j) -((n-j)/2);
            }
           break;}
        if (j+i<=n){
             if ((j+1)%2!=0 && i%2){
                blacka+= i/2+1;
                whitea+=i- i/2-1;
            }
            else {
                blacka+= i/2;
                whitea+= i -(i/2);
            }
            a+=i;
           j+=i;
           i++;
          //    watch (i);
        }
        else{
          if ((j+1)%2!=0 && (n-j)%2){
                blacka+= (n-j)/2+1;
                whitea+=(n-j)- (n-j)/2-1;
            }
            else {
                blacka+= (n-j)/2;
                whitea+= (n-j) -((n-j)/2);
            }
                  a+=n-j;
           break;}
    }

    cout << blacka << " " <<whitea<< " "<< blackb<< " "<<whiteb <<endl;
    
    // fr (i, 0, n)
    //     cin >> v[i];
    // cout <<  a<<endl;
        
    
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