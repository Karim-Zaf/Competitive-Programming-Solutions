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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int work(string s){
    int n = (int)s.size();
    vector<int> is_pal(n + 4, 1);
    for (int i = n / 2 - 1; i >= 0; i--){ is_pal[i] = (is_pal[i + 1] && s[i] == s[n - i - 1]); }
    
    
    map<char,int> one, two;
    for (int i= 0 ; i<n/2;i++){
        one[s[i]]++;
        two[s[n-i-1]]++;
        int ok = 1;
        for (char c = 'a' ; c<='z'; c++){
            if ( one[c]!=two[c])ok =0;
        }
        if (ok && is_pal[i+1])return i+1;
    }

    map<char, vector<int>> mp;
    int curr = 0 ;
    for (int i = 0; i < n; i++) mp[s[i]].push_back(i); 
    for (auto [val,v] : mp){
        int sz = v.size();
        curr = max(curr, v[sz / 2 - 1]+1);
    }
 
    return curr;
}

void Solve(){
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    int i = 0, j = n - 1;
    while (i < j && s[i] == s[j]){
        i++;
        j--;
    }

    string nw_s = "";
    for (int k = i; k <= j; k++)nw_s += s[k];
    s = nw_s;

    ans = work(s);
    reverse(all(s));
    ans = min(ans, work(s));

    cout << ans << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}
