
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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MOD mod
#define INF (ll)(1e18)

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int n ; 
    cin >> n; 

    vector <vector<int>> res ; 
    vi v (n); 
    multiset <pair <int ,int >>  other ; 
    for (int i= 0 ;i<n ; i++ ) cin >> v[i] ; 
    for (int i= 0 ;i<n ; i++ ){
        pair <int,int> p = make_pair(v[i] ,0 ) ;
        auto pos = other.upper_bound (p)  ;
        // kar (pos == other.begin());
        if (pos == other.begin() ) {
            vector<int> add ;
            add.pb(v[i]) ;
            res.pb(add);
            other.insert({v[i],res.size()-1});
        }
        else {
            pos--;
            pair <int , int > p = *pos;
            res[p.S].pb(v[i]) ; 
            other.erase(p);
            other.insert(make_pair(v[i],p.S));
        }
    }
    for (auto j : res){
        for (auto x  : j ) 
            cout <<  x<< " " ; cout <<endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}