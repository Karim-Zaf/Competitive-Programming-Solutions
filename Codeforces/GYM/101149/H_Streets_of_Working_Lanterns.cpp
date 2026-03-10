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
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
 
const ll N = 1e6 + 4 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 , INF = 1e18 ;
 
void solve (){
    string ch ; 
    cin >> ch ;
    int n = ch.size(); 
    vector <int>  vis(n); 
    set <int , greater<>> s ; 
    if (n%2) {cout << "Impossible" << endl; return;}
    int curr = n / 2 , mahloul = 0 , msaker = 0 ; 
    for (int i= 0 ;i<n ;i++){
        mahloul += ch[i]=='(';
        msaker += ch[i]==')';
    }
    int i= 0 ;
    while (i<n && mahloul <curr ){
        if (ch[i]=='?'){
            mahloul++;
            ch[i]='(';
        }
        i++;
    }
    i= n-1 ;  
    while (i>=0 && msaker <curr ){
        if (ch[i]=='?'){
            msaker++;
            ch[i]=')';
        }
        i--;
    }   
    for (int i= 0 ;i<n ;i++)
        if (ch[i]=='(') s.insert(i);
    
    for (int i= n-1 ; i>=0 ;i--  ){
        if (ch[i]==')') {
            if (s.empty()){cout << "Impossible"<< endl; return;}
            vis[*s.begin()]=1;
            s.erase(*s.begin());
        }else if (!vis[i]){
            cout << "Impossible"<< endl; return;
        }
    }
 
    cout << ch << endl;
 
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}