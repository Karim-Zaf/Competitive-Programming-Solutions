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

const ll N = 1e12 , MOD =1e9+9, mod=1e9+7, INF = 1e18 ;



void solve(){
    int K;
    string s;
    cin >> s;
    vector<char> bad(26);
    set<ll> st;
    for (int i = 0; i < 26; i++) cin >> bad[i];
    cin >> K;
    int N = s.size();
    for (int l = 0; l < N; l++){
        int cnt = 0;
        string tmp = "";
        ll hash = 0 , pow = 1 ;
        for (int r = l; r < N; r++){
            cnt += (bad[s[r] - 'a'] == '0');
            if (cnt > K) break;

            hash = (hash + pow* (s[r]-'a'+1)) ;
            pow *= 9973 ;

            st.insert(hash);
        }
    }
    cout << st.size() << endl;
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