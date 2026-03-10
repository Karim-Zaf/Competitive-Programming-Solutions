/**                         _       _______
                            |     |____   /
                           | |          / /
                           | |         / /
                           | |____    / /
                           |______|  /_/
**/
 
#include<bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;
#define         yes {cout<<"Yes"<<endl;return;}
#define         no {cout<<"No"<<endl;return;}
#define         CR(_) {cout<<_<<endl;return;}
#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
//const           ll MOD = LLONG_MAX;
//const           ll MOD = 998244353;
const           ll MOD=1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           int N=2e5+5;
const           ll INF=1e18;
const           int L = log2(N)+1;
void solve(){
    ll n;cin>>n;
    vl v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    sort(all(v));
    set<ll>s;
    for(ll i=0;i<n;i++){
        s.insert(v[i]);
    }
    if(s.size()==1&&v[0]==0){
        CR(0);
    }
    if(v[0]>=0)CR(1);
    if(v[n-1]<=0)CR(1);
    CR(2);
}
int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        freopen("hanya.in", "r",stdin);
        //freopen("output.txt", "w",stdout);
        int _=1;
        cin >>_;
        //cout<<fixed<<setprecision(6);
        while(_--)solve();
}