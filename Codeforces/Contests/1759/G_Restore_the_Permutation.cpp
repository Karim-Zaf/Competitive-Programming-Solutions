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

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve() {
    int n ,flag =false;
    cin>>n;
    vector <int> v(n) , mp(n+1,-1) , ans(n);
    for (int i=0; i<n/2; i++){
        cin >> v[i] ;
        if (mp[v[i]]!=-1)flag=true;
        mp[v[i]]=i;
    }
    if (flag) {cout<<-1<<endl;return;}
    set<int> s;
    for (int i= n; i>=1 ; i--){
        if (mp[i]==-1){
            if (s.empty()){cout<<"-1\n";return;}
            int rass=*prev(s.end());
            ans[rass]=i;
            s.erase(rass);
        }else s.insert(mp[i]);
    }
    for (int i= 0 ;i<n/2 ; i++)cout << ans[i]<< " " << v[i] << " " ; cout << endl;
}

int32_t main(){
     #ifndef ONLINE_JUDGE
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
    cin >> Test_case ;
    while (Test_case--) Solve();
}