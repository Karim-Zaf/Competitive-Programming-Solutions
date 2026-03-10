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

const ll N = 1e6+ 5 ,  MOD =1e9+7, mod=1e9 +7, INF = 1e18+5;

void solve(){
    string s , nws ="" ;
    cin >> s ;
    int n= s.size() , ekher = INF;
    for (int i= 0 ; i<100; i++) nws +='0';
    s = nws + s ;
    n = s.size() ;
    int i= n- 1 ;
    while (i>=0){
        if (s[i]=='9'){
            ekher = i ;
            for (int j= i-1 ; j>=0 ; j--){
                if (s[j] =='9') s[j]= '0';
                else {
                    s[j]++;
                    i = j+1;
                    break;
                }
            }
        }
        else if ((s[i]-'0')>=5){
            s[i-1]=s[i-1]+1 ;
            ekher = i ;
        }
        i--;
    }
    i= 0 ;
    while (s[i] == '0' && i< s.size()  )i++;
    for (int i= ekher ; i<n ;i++) s[i]= '0' ;
    if (i == s.size()) cout << 0 << endl;
    else {
        for (int j =i ; j< s.size() ;j++) cout << s[j] ; cout << endl;
    }

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);srand(time(0)); ll test_case=1;
    cin >> test_case ;
    while (test_case--)  solve() ;
}