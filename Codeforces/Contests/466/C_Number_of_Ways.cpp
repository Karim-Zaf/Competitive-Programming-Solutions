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

const ll N = 1e7 + 5 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

void solve() {
    int n ; 
    long long res=0 ;
    cin >> n;
    vector <long long> v(n+2) ,pref(n+2),suff (n+2);
    map <long long, vector<int>> mp ;
    for (int i= 1 ;i<=n ; i++)
        cin >> v[i] ;

    for (int i= 1 ; i<=n ; i++)
        pref[i] = pref[i-1] + v[i] ;
    for (int i= n ; i>=1 ; i--)
        suff[i] = suff[i+1] + v[i] ;
    for (int i= 1 ; i<=n ; i++)
        mp[suff[i]].pb(i) ;

    for (int i =1 ;i<=n-2 ;i++){
        if (pref[i]!=suff[i+1]/2 || suff[i+1]%2) continue;
        int pos = lower_bound(all(mp[pref[i]]),i+2) - mp[pref[i]].begin();
        res += (mp[pref[i]].size() - pos ) ;
    }

    cout << res <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}