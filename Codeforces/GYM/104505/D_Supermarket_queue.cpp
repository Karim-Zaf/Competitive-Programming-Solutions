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
 
const int  N=5e6+8,MOD=1e9+7,mod=1e9+7,INF=1e17;
 
void Solve(){
    int n , k ;
    cin >> n >> k ;
    set <pair <int,int>> sp ;
    set <int> s  ;
    queue <pair <int,int>> q[k+1];
    vector <int> ent(n+1) ;
 
    for (int i= 0 ;i<2*n ;i++){
        int x , p , f ;
        cin >>x >> p;
        if (x==1){
            cin >>  f ;
            sp.insert({i,p});
            q[f].push({i,p});
            ent[p]=f ;
        }else {
            auto curr = q[p].front() ;
            q[p].pop();
            auto it = sp.begin();
            vector <pair <int,int>> er ;
            while (it!=sp.end() && (*it).F <=curr.F){
                er.pb(*it);
                it++;
            }
            for (auto xx : er) {
                sp.erase(xx);
                if (xx.S!=curr.S)s.insert(xx.S) ;
            }
 
        }
        kar (sp);
    }
    cout << s.size() << endl;
    for (auto x: s) cout << x << " " ; cout << endl;
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0); int Test_case=1;
//    cin >> Test_case ;
    while(Test_case--)Solve();
}