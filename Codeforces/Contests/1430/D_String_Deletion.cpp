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
#define int ll
#define ld long double
const ll N =2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 1e18;
 
void solve(){
    int n , res = 0 ;
    string s ;
    cin >> n >> s ;
    vector <int> v ;
    int i= 0 ;
    while (i<n){
        v.pb(1) ;
        i++ ;
        while (i<n&& s[i]==s[i-1]) {v[v.size()-1]++ ;i++;}
    }
    set <int> se ;
    for (int j= 0 ; j<v.size(); j++)
        if (v[j]>1) se.insert(j) ;
    for (int i= 0 ; i<v.size(); i++) {
        res++ ;
        if (!se.empty()) {
            v[*se.begin()]--;
            if (v[*se.begin()] == 1)se.erase(*se.begin());
            if (*se.begin()==i) se.erase(*se.begin());
        }else {
            if (*se.begin()==i) se.erase(*se.begin());
            i++;
        }
    }
    cout << res << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}