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
 
 
const ll N = 1e3+2 ;
ll tab[N][N]  ;
ll n , m ;
vector<ll> vec[N] ;
void solve()
{
    map<ll,vector<pi>> mp ;
    cin>>n>>m ;
    for(ll i = 1 ; i<=n ; i++){
        for(ll j = 1 ;j<=m ; j++){
            ll  x ;
            cin>>x ;
            mp[x].pb({i , j}) ;
        }
    }
 
    ll tot = 0 ;
    vector<ll> ans(m+2) ;
    for(auto& x : mp){
        auto v = x.S ;
        sort(all(v)) ;
        vector<ll> rows ;
        for(auto& xx : v){
            ll i = xx.F , j = xx.S ;
            tab[i][j] = 1 ;
            tab[i][j] += tab[i-1][j] ;
            vec[i].pb(j) ;
            rows.pb(i) ;
        }
//        cout<<x.F<<endl;
//        for(int i = 1 ; i<=n ; i++){
//            for(int j = 1; j<=m ; j++){
//                cout<<tab[i][j]<<' ';
//            }
//            cout<<endl;
//        }
 
        for(ll k = 0 ; k<rows.size() ; k++){
 
            if(!k || rows[k]!=rows[k-1]){
                ll i = rows[k] ;
                stack<pair<ll,ll>> st ;
 
                int lst = -5 ;
                for(ll j : vec[i]){
                    if(j>lst+1){
                        while(!st.empty()) st.pop() ;
                        st.push({0 , j-1}) ;
                        ans[j-1] = 0 ;
 
                    }
                    while(!st.empty() && st.top().F>=tab[i][j]) st.pop() ;
                    ans[j] = ans[st.top().S] + (j - st.top().S)*tab[i][j] ;
                    tot += ans[j] ;
                    st.push({tab[i][j] , j}) ;
                    lst = j ;
                }
//                for(int j = 0 ; j<=m ; j++){
//                    cout<<ans[j]<<' ';
//                }
//                cout<<endl;
                for(ll j : vec[i]){
                    ans[j] = ans[j-1] = ans[j+1] =  0 ;
                }
            }
        }
 
 
 
        for(auto& xx : v){
            ll i = xx.F , j = xx.S ;
            tab[i][j] = 0;
            ans[j] = 0 ;
            vec[i].clear() ;
        }
 
 
 
    }
    cout<<tot<<endl;
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