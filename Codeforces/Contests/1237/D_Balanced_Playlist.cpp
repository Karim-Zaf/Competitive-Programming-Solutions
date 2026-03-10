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

const ll N = 2e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;

void solve(){
    int n , flag= 0 ;
    cin >> n ;
    vector <int> v(4*n),res(n) ;
    multiset <int,greater<>> ms ;
    for (int i= 0 ;i<n ; i++)cin >> v[i];
    for (int i= n ; i< 4*n ;i++) v[i]= v[i%n];
    for (int i= 0 ;i<n ;i++){
        if (flag >= 3*n){res[i]=-1; continue;}
        if (ms.empty()) ms.insert(v[i]);
        flag = max (i,flag);
        while (true) {
            if (*ms.begin()> 2*v[flag+1]) break ;
            ms.insert(v[++flag]);
            if (flag >= 3*n) break;
        }
        if (flag >=3*n) res[i]=-1 ;
        else res[i]= ms.size() ;
        ms.erase(ms.find(v[i]));
    }
    for (auto x :res ) cout << x << " "; cout << endl;
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