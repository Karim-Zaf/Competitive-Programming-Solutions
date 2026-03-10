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

const ll N = 1e7+5 , MOD =1e9+7, Q =2e5+3 ;

void solve (){
    int n , Node, Mn=0 , One = 0 , Two = 0   , Hesba = 0 ;   
    cin >> n; 
    set<int> graph[n+1] ; 
    vector <int> vis(n+1,0) ,  join(n+1, 0) ; 
    for (int i= 1 ;i<=n ; i++ ){
        cin >> Node;
        graph[i].insert(Node); 
        graph[Node].insert(i); 
    }

    function<void(int,int)> Dfs  = [&](int parent , int Index ) {
        join[Index] += (graph[parent].size()==1? 1 : 0 ) ; 
        vis [parent] = Index ; 
        for (int child : graph[parent] ) 
            if (!vis [child])
                Dfs (child, Index) ; 
    };  
    
    for (int i= 1 ; i<= n ; i++ )
        if ( ! vis [ i ] ) 
            Dfs(i,++Hesba) ;

    for (int i = 1 ; i<=Hesba ; i++ ) {
        One += join[i] == 1 ; 
        Two += join[i] == 2 ; 
        Mn +=  join[i] == 0  ; 
    }
    Mn += (Two ? 1 : 0 ) ;  
    One = max(0ll , ll(One - Two*2 )) ; 
    Mn += One/2 + One % 2 ; 
    cout << Mn  << " " <<Hesba <<endl ; 
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}