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

bool isGood(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(')
            balance++;
        else if (c == ')')
            balance--;
        
        if (balance < 0)
            return false;
    }
    return balance == 0;
}

void solve (){ 
    int n , cnt = 0 , taksima = -1 ;  
    string ch ;
    cin >> n; 
    cin >> ch ;
    set<int > s ; 
    vector <int> kodem_open (n) ,teli_open(n) , kodem_close(n) , teli_close(n) ,res (n)  ;  
    for (int i= 0 ;i<n ; i++) {
        kodem_open[i] = ( ch[i] == '(' ? 1 : 0 ) ; 
        teli_open[i] = ( ch[i] == '(' ? 1 : 0 ) ; 
        kodem_close[i] = ( ch[i] == ')' ? 1 : 0 ) ; 
        teli_close[i] = ( ch[i] == ')' ? 1 : 0 ) ; 
    }
    for (int i = 1; i<n  ;i++){
        kodem_open[i]+= kodem_open[i-1] ;
        kodem_close[i]+= kodem_close[i-1] ;
    } 
    for (int i = n-2; i>=0  ;i--){
        teli_open[i]+= teli_open[i+1] ;
        teli_close[i]+= teli_close[i+1] ;
    }
    if (teli_close[0] != teli_open[0] || n%2){cout <<-1 <<endl; return;}
    for (int i= 0 ;i<n-1 ;i++){
        if (kodem_close[i]== teli_open[i+1]){
            taksima = i ; 
            break ; 
        } if (kodem_open[i]== teli_close[i+1]){
            taksima = i ; 
            break ; 
        }
    }
    string e = ch ; 
    reverse(all(e)) ; 
    if (isGood(ch)|| isGood(e)) {cout << 1 <<endl; while (n-- ) cout << "1 " ; cout <<endl;return; } 
    if (taksima == -1 ){ cout << -1 <<endl; return ; }
    for (int i=0 ; i<=taksima ; i++){
        res[i] =  (( ch[i]=='(') ? 1 : 2) ;
        s.insert(res[i]);
    } for (int i=taksima+1 ; i<n ; i++){
        res[i] =  (( ch[i]==')') ? 1 : 2) ;
        s.insert(res[i]) ; 
    }
    if ( s.size() == 2 ){ cout << 2 <<endl; for (auto x : res ) cout << x << " "; cout <<endl;}
    else {cout << 1 <<endl; while (n-- ) cout << "1 " ; cout <<endl;} 
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif 
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    cin >> test_case ; 
    while (test_case--)  solve() ;
}