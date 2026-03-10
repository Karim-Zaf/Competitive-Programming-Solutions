/*
Konnitchiwa
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
typedef priority_queue<int> PQI;
typedef __int128 lll;
#define ll long long int
#define db double
#define fl float
#define lld long long double
#define pb push_back
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout<<"NO"<<endl;
#define affichi(v,n) for(int i=0;i<n;i++)cout<<v[i]<<'-';
const ll mod=                    1e9+7;
// #define fr(i,a,b) for(ll i = a; i < b; i++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
const ll N=1e9;
#define cube(u) (u)*(u)*(u)
 
 
void local()
{
  #ifndef ONLINE_JUDGE
 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
}
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
 
bool is_prime(ll n){
    for(ll i=2;i*i<=n;i++)if(n%i==0)return 0;
    return n!=1;
}
 
lll square_serie(lll n){
    return (n*(n+1)*(2*n+1)/6);
}
 
bool comp(pair<ll ,ll>a,pair<ll ,ll>b){
    if(a.F!=b.F)return a.F<b.F;
    return a.S<b.S;
}
 
 
ll num(string s){
    ll ans=0;
    for(int i=0;i<s.size();i++){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
 
 
 

void solve(){
ll a , b ; cin >> a >> b ;
    cout << a*b << endl;
}
 
 
 
int main()
{
    fast
    local();
    int t=1;
     // cin >> t;
    while (t--)solve();
    return 0;
}