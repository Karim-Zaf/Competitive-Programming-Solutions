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
#define endl '\n'
 
const ll N = 1e6 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
 
#define int ll
 
        
vector <long long> primes ;
 
void sieve(){
    vector <int> visited(N) ;
    for  (int i =2 ; i<N ; i++){
        if (visited[i]) continue;
        primes.push_back(i) ;
        for ( int j=i ; j<N ; j+=i)
            visited[j]=1;
    }
}
 
vector<pair<int,int>> factors(int n){
    vector<pair<int,int>> res;
    for(int i = 0; i < primes.size() && primes[i]*primes[i] <= n;i++){
        if(n % primes[i]) continue;
        int cnt = 0 ;
        while(n % primes[i] == 0){
            n /= primes[i];
            cnt ++;
        }
        res.push_back({primes[i],cnt});
    }
    if(n > 1)res.push_back({n,1});
    return res;
}
 
long long binpow(long long a, long long k){
    long long res = 1;
    while (k){
        if (k % 2) 
            res = (res * a); 
        a = (a*a);
        k/=2 ;
    }
    return res ;
}
 
void solve(){ 
 
    ll x , prd = 1 , g=-1;  
    cin >> x; 
    sieve();
    vector < pair<int,int>> f1 = factors(x);
    vector < pair<int,int>> f2 = factors(x);
    for (auto d : f1){
        prd *= (d.S +1 );
    }
 
 
    for (int i= 0 ; i< f2.size(); i++){
        ll suite = f2[i].S;
        suite = suite*(suite+1)/2 ;
        f2[i].S = suite *(prd/(f1[i].S+1));
        g= (g==-1? f2[i].S: __gcd(f2[i].S,g));
    }
 
    if (x==1){cout << "1 1\n"<< endl;return;}
    ll a= 1 ;
    for (auto d : f2){
        a*=binpow (d.F,d.S/g);
    }
    cout << a << " "<< g << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    // cin >> test_case ;
    while (test_case--)  solve() ;
}
 
 
 
// Failure gives you two choices: You stay down or You get up ;)