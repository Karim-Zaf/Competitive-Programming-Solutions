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
#define endl "\n"
#define MOD mod
#define INF (ll)(1e18)

const ll N = 2e5+5 , MOD =1e9+7, Q =2e5+3 ;

vi graph[N] ; 
int vis [N] ,kbal [N] , par[N] ;
map <pair<int,int>, int> mp ;
void dfs ( ll parent){
    vis [parent]= 1 ; 
    for (auto child: graph[parent]){
        if (! vis[child]){
            kbal[child]= kbal[parent] ;
            par[child] = parent ;
            int x =parent,y= par[parent], x2=parent , y2=child ;  
            if (x>y )swap(x,y); 
            if (x2>y2 )swap(x2,y2); 
            pair<int,int> p1 =  make_pair(x,y) ,p2 = make_pair(x2,y2) ;
            if ( par[parent]!=-1 && mp[p2]<mp[p1]){
                kbal[child]++ ;
            }
            dfs(child);
        }
    }
}

void solve (){
    int n,res = 1  ; 
    cin >> n; 
    memset(vis , 0 , sizeof(vis)) ; 
    for (int i = 0 ;i<=n; i++)graph[i].clear() ;
    for (int i = 0 ;i<=n; i++)kbal[i]=1 ;
    for (int i = 0 ;i<=n; i++)par[i]=-1 ;
    for (int i = 0 ;i<n-1; i++){
        int x , y ; 
        cin >> x >> y ;
        if ( x > y ) swap(x,y);
        mp[make_pair(x,y)]  = i ;
        graph [x] .pb(y) ;
        graph [y] .pb(x) ;
    }
    dfs(1) ;
    for (int i =1 ;i<=n ; i++){
        res = max (res , kbal[i]) ;
    }
    cout << res <<endl;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}