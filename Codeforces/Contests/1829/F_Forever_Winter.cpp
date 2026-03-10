

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

const ll N = 1ll<<27 , MOD =1e9+7, Q =2e5+3 ;

void solve (){  
    vi graph[300]; 
    ll n , m , x , y ; 
    cin >> n >> m; 
    for (ll i=  0 ;i<m ; i++ ){
        ll a, b ; 
        cin >> a >> b ; 
        graph[a].pb (b ) ; 
        graph[b].pb (a ) ; 
    }
    for (auto parent  : graph)
        if (parent.size()==1)
            for (auto child  : parent ) 
                if ( graph[child].size() > 1 )
                    for (auto ch: graph[child] ) 
                        if ( graph[ch] .size()> 1 ){
                            cout <<graph[ch].size() << " "<< graph[child].size()-1 <<endl;
                            return;
                        }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}