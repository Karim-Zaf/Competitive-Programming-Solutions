#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef long double ld ;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353   ;
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
void nop(){cout<<-1<<endl;return;}

void solve()
{
    set<pair<int,int>> s ;
    map<int,int> mp ;
    int n , q ;
    cin>>n>>q ;
    vector<int> t(q+1) , p(q+1) , winner(q+1);
    for(int i = 1 ; i<=n ; i++){
        s.insert(make_pair(0 , -i)) ;
    }
    winner[0] = 1 ;
    for(int i = 1 ; i<=q;  i++){
        cin>>t[i]>>p[i] ;
        auto old = make_pair(mp[t[i]] , -t[i]) ;
        if(s.find(old)!=s.end()){
            s.erase(old) ;
        }
        mp[t[i]] += p[i] ;
        auto _new = make_pair(mp[t[i]] , -t[i]) ;
        s.insert(_new) ;
        auto curr = *prev(s.end()) ;
        winner[i] = -curr.second ;
    }
    for(int i = q; i>=0 ; i--){
        if(winner[i]!=winner[q]){
            cout<<i+1<<endl;
            return ;
        }
    }
    cout<<0<<endl;
    return ;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin) ;
        freopen("output.out","w",stdout) ;
    #endif
    io() ;
    ll tt = 1 ;
    cin>>tt ;
    while(tt--){
        solve() ;
    }

    return 0 ;
}