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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nop cout<<"-1"<<endl;
#define int ll

const ll N = 4e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
vector <int> primes;
void sieve(){
    vector <int> visited(N) ;
    for  (int i =2 ; i<N ; i++){
        if (visited[i]) continue;
        primes.push_back(i) ;
        for ( int j=i ; j<N ; j+=i)
            visited[j]=1;
    }
}
void solve(){
    int n , one = 0 ,sum = 0 , i= 0 , two = 0 ;
    cin >> n ;

    vector <int> v(n),res ;
    sieve();
    for (auto &x: v) {
        cin >> x;
        one += (x == 1);
        two += (x == 2);
    }
    kar(one);
    while (one >0 || two>0) {
        int diff = primes[i]-sum;
        if (diff <=0) diff = primes[++i]-sum;
        if (diff>=2 && two ) {
            two--;
            res.pb(2);
            sum+=2;
       }else if (one) {
            one --;
            res.pb(1);
            sum+=1;
        }else if (two){
            two--;
            res.pb(2);
            sum+=2;
        }
    }
    for (auto x : res) cout << x << " " ; cout << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}


// Failure gives you two choices: You stay down or You get up ;)