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

const ll N = 2e5+ 8 ,  MOD =1e9+7, mod=1e9+7, INF = 3e18 +87;



void solve(){
    int n;
    string res ;
    cin >> n;
    char c = 'a';
    set <int>divisors;
    for (int i= 0;i<n ;i++) res+= 'a';
    for (int i = 1 ; i*i<=n ;i++){
        if (n%i)continue;
        divisors.insert(i);
    }
    for (int i= 0 ;i<n ;i++) {
        char c = 'a';
        vector <int> vis(27);
        for (int d : divisors) {
            int d2 = n/ d;
            if (i - d >= 0)vis[res[i-d]-'a']=1 ;
            if (i - d2 >= 0)vis[res[i-d2]-'a']=1 ;
        }
        for (int j = 0 ;j<27 ;j++){
            if (!vis[j]) {
                res[i]= char('a'+j);
                break;
            }
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