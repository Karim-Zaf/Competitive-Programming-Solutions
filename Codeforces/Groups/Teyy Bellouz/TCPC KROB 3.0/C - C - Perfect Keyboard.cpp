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

    long long N_cmp = sqrt(1e9); 
    map <long long , bool > g ; 
    bool ok;
    string res = "" ;  

    map<char, set<char>> graph ; 
    map<char, char> bou ; 
    map <char , bool> vis ;

    void Dfs_char (char parent ){
        res += parent ; 
        vis [parent] = true ; 
        for (char child : graph[parent]){
            bou[child]= parent ; 
            if ( vis [child] && bou[child]!= parent) {
                ok = false ; 
                return ; 
            }
            else if (!vis[child]){
                Dfs_char ( child) ; 
            }
        }
    }

    void solve (){
        char start=' ' ;
        ok =true;  
        string ch ;
        cin >> ch ;
        for (char c = 'a' ; c<='z' ; c++) vis[c] = false ; 
        for (char c = 'a' ; c<='z' ; c++) graph[c].clear() ; 
        for (int i= 1 ; i<ch.size()  ;i++ ){
            if (ch[i-1]!= ch[i])
            graph[ch[i]].insert (ch[i-1]) ;
            if (ch[i]!= ch[i-1])
            graph[ch[i-1]].insert(ch[i]) ;  
        }
        for (auto x : graph) {
            if (x.S.size() == 1 ) start= x.F ;
            if (x.S.size() >=3){no return; }
        }
        res = "" ;  
        Dfs_char(start) ;
        for (char c = 'a' ; c<='z' ; c++) if ( !vis [c]) res+= c ; 
        if (ok && start!=' ' || ch.size()==1){
            yes 
            if (ch.size()==1){
                for (char c = 'a' ; c<='z' ; c++) 
                    if ( !vis [c]) cout<<c ;
                cout <<endl; 
                return;
            }
            cout << res<<endl ;
        }else {no} 

    }


    int32_t main(){
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
        #endif 
        ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
        cin >> test_case ; 
        while (test_case--)  solve() ;
    }