//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


map<string,bool> f ;
map<char,int> g ;

int work(string s){
    int ret = 0;
    ret += g[s[0]] * 16 ;
    ret += g[s[1]] ;
    return ret ;
}   

bool check_C(vector<string> &vec){
    int n = (int)vec.size() ;
    int idx = -1 ;
    for(int i = 0 ; i < n ; i++){
        if(vec[i][0] == '0' && vec[i][1] == '0'){
            idx = i ;
            break; 
        }
    }
    if(idx == -1) 
        return false ;
    for(int i = 0 ; i < idx ; i++)
        if(!f.count(vec[i]))
            return false ;
    return true ;
}

bool check_P(vector<string> &vec){
    if(vec.empty()) return false ;
    int len = work(vec[0]) ; 
    if((int)vec.size() < len + 1) return false;
    for(int i = 1 ; i <= len ; i++)
        if(!f.count(vec[i])) return false ;
    return true ;
}

void solve(){
    vector<char> c ;
    for(char x = '0' ; x <= '9' ; x++) c.push_back(x) ;
    for(char x = 'a' ; x <= 'f' ; x++) c.push_back(x) ;
    for(char x = '0' ; x <= '9' ; x++){
        g[x] = (int)(x - '0') ;
    }
    for(char x = 'a' ; x <= 'f' ; x++){
        int y = (int)(x - 'a') + 10 ; 
        g[x] = y ;
    }
    for(char x = '2' ; x <= '7' ; x++){
        for(char y : c){
            string cur = "" ;
            cur += x;
            cur += y ;
            f[cur] = true ;
        }
    }
    vector<string> vec ; 
    while(!cin.fail()) {
        string s ; 
        cin >> s ; 
        if(!s.empty()) 
            vec.push_back(s) ;
    }
    bool ok1 = check_C(vec) ;
    bool ok2 = check_P(vec) ;
    if(ok1 && ok2) cout << "Both" << endl;
    else if(ok1) cout << "C" << endl;
    else if(ok2) cout << "Pascal" << endl;
    else cout << "None" << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}