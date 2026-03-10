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
#define int __int128
#define endl '\n'
 
const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
vector <int> diviseurs[N];
 
void Solve() {
    for (int i= 1 ; i<N; i++)
        for (int j=i ; j<N ; j+=i )
            diviseurs[j].pb(i);
    ll a , s , l ,r ,ans = 0;
    cin >> a >> s >> l >> r ;
    if (s==a) {cout << 1 << endl; return;}
    for (int curr = l ; curr <=r ; curr ++){
        int diff = a - curr ;
        if (diff<=0) diff *=-1;
        vector <int> vect ;
        if (curr <= a) {
            vect=diviseurs[diff];
        }else vect.pb(diff);
 
        for (auto raison : vect){
            int premier_terme = curr;
            if (curr>=a) premier_terme = a;
            int left = 0 , right= 2e5 , nb = -1 ;
            while (left<=right){
                int md = left + (right - left) /2;
                int exp_sum = md * (2*premier_terme+ (md-1)*raison)/2 ;
                if (exp_sum>=s){
                    nb = md ;
                    right = md -1;
                }else left = md+1 ;
            }
            int dernier_terme = premier_terme + (nb-1)*raison ;
            int sum =nb* (premier_terme+ dernier_terme)/2 ;
            if (dernier_terme <=r && dernier_terme >=a && sum == s) {
                if (curr <=a){
                    ans ++;
//            cout << premier_terme<< " " << dernier_terme << " " << raison << " " << sum << endl;
                }
                else if (dernier_terme>=curr){
                ans ++;
//            cout << premier_terme<< " " << dernier_terme << " " << raison << " " << sum << endl;
                }
            }
        }
    }
    cout << ans << endl;
}
 
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}