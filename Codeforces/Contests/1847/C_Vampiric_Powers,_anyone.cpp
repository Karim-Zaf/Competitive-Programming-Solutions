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
 
const ll N = 1e5 + 8 , MOD =1e9+7, mod=1e9+7, INF = 1e18 ;
 
void solve(){
    int n , ad= -1 , xr = -1, res = 0  ;
    cin >> n ;
    vector <int> v(n) , pref(n);
    for (int i= 0;i<n ;i++)
        cin >>v[i];
    pref[0]= v[0];
    for (int i= 1 ;i<n ;i++)
        pref[i]= pref[i-1]^v[i];
    for (int j= (1<<8) ; j>=0; j--) {
        vector <int> mp(1<<9);
        for (int i = 0; i < n; i++) {
            if (mp[j^pref[i]]||pref[i]==j){cout << j << endl ; return;}
            mp[pref[i]]=1 ;
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
 
// Failure gives you two choices: You stay down or You get up ;)