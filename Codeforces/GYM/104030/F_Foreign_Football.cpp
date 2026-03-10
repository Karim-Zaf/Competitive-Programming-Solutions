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
 
const int  N=2e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
 
const int B = 9973 , B2 = 1e9+3;
 
int puiss1[N], puiss2[N] ,inv1[N], inv2 [N];
 
ll binpow(ll a, ll k, ll res =1){
    while (k){
        if (k % 2) res = (res * a)%MOD;
        a = (a*a)%MOD;k/=2 ;
    }return res%MOD ;
}
 
ll modinv(ll a){return binpow(a,MOD-2);}
ll mult(ll a, ll b){b%=MOD;return a%MOD*b%MOD;}
ll add (ll a, ll b){ return ((a%mod + b%mod)%mod + mod)%mod;}
 
vector<int> pref[505][505][2];
string t[505][505];
int n ;
 
void build(int i, int j){
    vector<int> & pr = pref[i][j][0] ;
    string & st = t[i][j] ;
    pr.resize(t[i][j].size()+5) ;
    for (int k=1 ; k<=st.size() ;k++)
        pr[k]=add(pr[k-1], mult(st[k-1],puiss1[k]));
 
    vector<int> &pr2 = pref[i][j][1] ;
    pr2.resize(t[i][j].size()+5) ;
    for (int k=1 ; k<=st.size() ;k++)
        pr2[k]=add(pr2[k-1], mult(st[k-1],puiss2[k]));
}
 
pair<int,int> query (int i , int j , int l , int r){
    vector<int> &pr = pref[i][j][0] ;
    if (r>pr.size()) return {INF,INF};
    int one = mult (add(pr[r],-pr[l-1]),inv1[l]);
    vector<int> &pr2= pref[i][j][1];
    int two = mult (add(pr2[r],-pr2[l-1]),inv2[l]);
    return make_pair(one,two);
}
 
 
void Solve() {
    cin >> n ;
    vector<string> ans(n+1);
    vector<int>sz(n+ 1) ;
    for (int i= 0; i<N ;i++) {
        puiss1[i] = binpow(B,i);
        puiss2[i] = binpow(B2,i);
        inv1[i] = binpow(puiss1[i],MOD-2) % mod ;
        inv2[i] = binpow(puiss2[i],MOD-2) % mod ;
    }
 
    vector<pair<int,int>> hsh (n+1) ;
    for (int i= 1; i<=n ; i++){
        for (int j= 1; j<=n ;j++){
            cin >> t[i][j] ;
            build(i,j) ;
        }
    }
 
    int cnt = 0, mn = INF ;
    for (int i= 1; i<=n ; i++) if (t[i][i]!="*"){cout << "NONE\n"; return;}
    for (int i= 2; i<=n ;i++) mn =  min (mn , (int)t[1][i].size()) ;
 
    for (int final_sz = 1 ; final_sz < mn ; final_sz ++ ){
        hsh[1] = query(1,2,1,final_sz);
        sz[1] = final_sz ;
        for (int i= 2 ;i<=n ;i++) {
            hsh[i] = query(1,i,final_sz+1,t[1][i].size());
            sz[i] =t[1][i].size() - final_sz ;
        }
 
        int flag =1;
        for (int i= 1; i<=n ;i++){
            for (int j= 1; j<=n ;j++){
                if (i==j) continue;
                if (t[i][j].size()!=t[j][i].size()) {cout << "NONE\n"; return;}
 
                if (!(query(i,j,1,sz[i])==hsh[i] &&
                query(i,j,sz[i]+1,t[i][j].size())==hsh[j])) flag = 0 ;
            }
        }
 
        cnt += flag ;
        if (cnt>1){cout << "MANY\n"; return;}
        if (flag){
            for (int j=0 ; j<final_sz; j++)
                ans[1]+= t[1][2][j];
            for (int i= 2 ;i<=n ;i++)
                for (int j=final_sz ; j<t[1][i].size(); j++)
                    ans[i]+= t[1][i][j];
        }
    }
    if (cnt==0){cout << "NONE\n"; return;}
 
 
    cout << "UNIQUE\n";
    for (int i= 1; i<=n ;i++) cout << ans[i] << endl; cout << endl;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}