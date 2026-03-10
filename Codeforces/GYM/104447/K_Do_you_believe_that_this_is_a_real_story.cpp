#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
 
void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
 
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
 
void nop() {
    cout << -1 << endl;
    return;
}
 
 
 
 
int n ;
int bef(int node)
{
    node -= 3 ;
    if(node<1) node += n ;
    return node ;
}
int nex(int node)
{
    node += 3 ;
    if(node>n) node -= n ;
    return node ;
}
 
void solve() {
    cin>>n ;
    if(n%3==0){
        no ; return ;
    }
    yes ;
    priority_queue<int> pq ;
    pq.push(-1) ;
    vector<int> vis(n+1) ;
    vis[1] = 1;
    vector<int> ans ;
    while(!pq.empty()){
        int node = -pq.top() ;
        pq.pop() ;
        ans.pb(node) ;
        int l = bef(node) ;
        int r = nex(node) ;
        if(!vis[l]){
            vis[l] = 1 ;
            pq.push(-l) ;
        }
        if(!vis[r]){
            vis[r] = 1 ;
            pq.push(-r) ;
        }
    }
    for(int i = 0 ; i<n-1 ; i++) cout<<ans[i]<<' ';cout<<endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    io();
    ll tt = 1;
    cin>>tt ;
    while (tt--) {
        solve();
    }
 
    return 0;
}