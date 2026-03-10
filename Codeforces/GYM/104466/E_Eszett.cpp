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
 
const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 5e18 ;
 
void solve(){
    string s ;
    cin >> s ;
    queue <pair <string, int>> q;
    set <string> ss ;
    q.push({"", 0}) ;
 
 
    while (!q.empty()){
        string curr = q.front().F;
        int idx = q.front().S ;
        q.pop();
        string nw = curr;
        for (int i= idx ; i<s.size(); i++){
            if (i<s.size()-1 && s[i]==s[i+1] && s[i]=='S'){
                q.push({ nw +"ss", i +2});
                q.push({ nw +"B", i +2});
            }
            nw+= tolower(s[i]);
            if (i >= s.size()-1) {ss.insert(nw) ;}
        }
            if (idx >= s.size()-1) {ss.insert(nw) ;}
    }
    for (auto x : ss)cout << x << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
//    cin >> test_case ;
    while (test_case--)  solve() ;
}