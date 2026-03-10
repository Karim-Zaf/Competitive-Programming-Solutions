#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define int ll
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 700100 ; 
int a[N] , p[N] ; 
ordered_set s[N] ; 
set<array<int,3>> f ;
map<pair<int,int>,int> ans ;
multiset<int> st ; 
vector<int> v ; 

void solve(){
    int n ;
    cin >> n ; 
    v.clear() ; 
    st.clear() ; 
    f.clear() ; 
    ans.clear() ; 

    for(int i=1 ; i<=n ; i++) cin >> a[i] ;
    for(int i=1 ; i<=n ; i++) cin >> p[i] ;
    int g = 0 ; 
    for(int i=n ; i>=1 ; i--) {
        int k = s[1].order_of_key({a[i] , -inf}) ; 
        g += k ; 
        s[1].insert({a[i],i}) ; 
    } 

    int c = 2 ;
    f.insert({1,n,1}) ; 
    ans[{1,n}] = g ;
    st.insert(g) ; 


    for(int i=1 ; i<=n ; i++){
        int gg = *prev(st.end()) ; 
        v.pb(gg) ; 
        int idx = (gg ^ p[i]) ;

        auto it = f.upper_bound({idx,(int)2e9,(int)2e9}) ; 
        assert(it != f.begin()) ; 
        it-- ; 
        auto [l,r,id] = *it ;

        f.erase(it) ;

        int p = ans[{l,r}] ; 
        st.erase(st.find(p));

        int len1 = idx - l ; 
        int len2 = r - idx ;
        int new_id = c++ ;

        if(len1 < len2){
            int ans1 = 0 ; 
            for(int j=idx-1 ; j>=l ; j--) {
                s[id].erase({a[j],j}) ; 
                ans1 += s[new_id].order_of_key({a[j] , -inf}) ; 
                s[new_id].insert({a[j],j}) ;         
            }
            s[id].erase({a[idx], idx}) ; 
            int minus = ans1 ; 
            for(int j = l ; j<=idx ; j++)
                minus += s[id].order_of_key({a[j],-inf}) ; 
            minus += (int)s[new_id].size() - s[new_id].order_of_key({a[idx] , inf}) ; 
            if(l<=idx-1) {
                f.insert({l,idx-1,new_id}) ; 
                ans[{l,idx-1}] = ans1 ;
                st.insert(ans1) ;  
            }
            int ans2 = p - minus ; 
            if(idx+1 <= r){
                f.insert({idx+1,r,id}) ; 
                ans[{idx+1,r}] = ans2 ;
                st.insert(ans2) ;  
            }
        }else{
            int ans1 = 0 ; 
            for(int j=r ; j>idx ; j--) {
                s[id].erase({a[j],j}) ; 
                ans1 += s[new_id].order_of_key({a[j] , -inf}) ; 
                s[new_id].insert({a[j],j}) ;         
            }

            int minus = ans1 ; 
            s[id].erase({a[idx], idx}) ; 
            for(int j=idx ; j<=r ; j++)
                minus += (int)s[id].size() - s[id].order_of_key({a[j],inf}) ; 
            
            minus += s[new_id].order_of_key({a[idx] , -inf}) ; 


            int ans2 = p - minus ; 
            if(l<=idx-1) {
                f.insert({l,idx-1,id}) ; 
                ans[{l,idx-1}] = ans2 ;
                st.insert(ans2) ;  
            }
            if(idx+1 <= r){
                f.insert({idx+1,r,new_id}) ; 
                ans[{idx+1,r}] = ans1 ;
                st.insert(ans1) ;  
            }
        }
    }
    for(int i=0 ; i<(int)v.size() ; i++){
        cout << v[i] ; 
        if(i+1<(int)v.size()) cout << " ";
    }
    cout << endl ; 
    for(int i=0 ; i<=c ; i++) s[i].clear() ; 
}

int32_t main(){
    fast 
    ll t = 1 ; 
    cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  