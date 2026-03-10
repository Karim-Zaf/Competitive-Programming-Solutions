/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}
 
const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;
 
vector <int> v, sieve[N] , vis (N),  mp (N);
 
void solve(){
    int n , k , left , l = 0 , r = 0 ; 
    cin >> n >> k >> left  ;
    set <int> s;
    vector <int> v(3);
    int right = n - left - k ;
    int res = left + right ; 
    v[0] = k ;
    v[1]= left;
    v[2]= right ;
    sort (all(v));
    map<int,int> mp ;
    for (auto x: v) mp[x]++;
    if (mp[1]==2) cout << 1 << endl;
    else if (mp[1]==3 ) cout << 2 << endl;
    else if (mp[2]==2 && mp[1]==1) cout << 2 << endl;
    else if (mp[2]==2 ) cout << 1 << endl;
    else if (mp[2]==3 ) cout << 3 << endl;
    else if (mp[3]==3 ) cout << 3 << endl;
    else if (mp[3]==2 && mp[1]) cout << 1 << endl;
    else if (mp[3]==2 && mp[2]) cout << 2 << endl;
    else if (mp[4]==3) cout << 2 << endl;
    else if (mp[4]==2 && mp[1]) cout << 1 << endl;
    else if (mp[4]==2 && mp[3]) cout << 1 << endl;
    else cout << 0 << endl;
 
 
 
}
 
int32_t main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
   #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
 
}