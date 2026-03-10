/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
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
#define int ll
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

string s="";

map<int,int> mp;

int eolve(string s ) {
    int n= s.size() ;
    vector<int> dp (n+2) ;
//    for (int i= 0 ;i<30; i++) cout << 'A' ; cout<< endl;
    dp[0]= 1 ;
    for (int i= 0 ; i<n; i++){
        if (s[i]=='A')dp[i+2]+= dp[i] ;
        dp[i+1]+=dp[i] ;
        kar (dp);
    }
    return dp[n] ;

}

void Fibonacci(){
    int one =1 , two = 1;
    mp[1]=0 ;
    for (int i= 1; ; i++){
        int curr = one + two ;
        if (curr>1e15) break;
        mp[curr]= i ;
        one = two ;
        two = curr ;
    }
}

string work(int x){
    string ret = "" ;
    for (int i= 0 ; i<mp[x] ; i++)ret+="A" ;
    ret+= "B";
    return ret ;
}

vector<int> v ;
map<int,string> dp ;

string go ( int n ){
    if (n==1) return "";
    if (dp.count(n))return dp[n];
    dp[n]="" ;
    for (auto x : mp){
        if (n%x.F) continue;
        string curr =work(x.F)+go(n/x.F);
        if ((curr <dp[n]||dp[n].size()==0)&& eolve(curr)==n) dp[n]= curr;
        curr =go(n/x.F)+work(x.F);
        if ((curr <dp[n]||dp[n].size()==0)&& eolve(curr)==n) dp[n]= curr;
    }
    return dp[n] ;
}

void Solve(){
    Fibonacci();

    int n;
    cin >> n ;
    s = go(n);
    if (eolve(s)!=n) cout <<  "IMPOSSIBLE\n";
    else cout << s << endl;

}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}