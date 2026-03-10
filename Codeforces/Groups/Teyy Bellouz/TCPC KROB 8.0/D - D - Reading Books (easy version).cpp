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
#define pi pair<ll,ll>
#define vi vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define non cout<<"-1\n";
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define INF (ll)(1e18)
template<typename T>void dbg(const T&x){for(auto&i:x)cout<<i<<' ';cout<<'\n';}

const ll N = 2e5+5 , MOD =1e9+7, mod=1e9+7, Q =2e5+3 ;

void solve (){
    int n, k ,salice = 0 , sbob = 0 ,res = 0, i= 0 ; 
    cin >> n >> k ; 
    priority_queue <int,vector<int>,greater<>> alice, bob , both ;
    vector<int> v (n);
    for (int i =0 ;i<n ; i++){
        int x,y,z;
        cin>> x >> y >> z ;
        if(y==1&&z==1)both.push(x);
        if(y==1&&z==0)alice.push(x);
        if(y==0&&z==1)bob.push(x);
    }
    while( (sbob<k || salice <k) && (!alice.empty() ||!bob.empty() || !both.empty())){
        if (salice>=k && !both.empty() && ! bob.empty()){
            sbob ++;
            if (bob.top()<=both.top()){
                res += bob .top();
                bob .pop();
            }else{
                res += both .top();
                both .pop();
            }
        }else if (sbob>=k && !both.empty() && ! alice.empty()){
            salice++;
            if (alice.top()<=both.top()){
                res += alice.top();
                alice.pop();
            }else{
                res += both.top();
                both .pop();
            }
        }
        if (!both.empty() && !alice.empty() && !bob.empty() && salice <k && sbob<k){
            sbob ++;
            salice++;
            if (bob.top()+ alice.top()<=both.top()){
                res+= bob.top()+ alice.top() ;
                bob.pop();
                alice .pop();
            }else {
                res += both.top() ;
                both.pop();
            }
        }else if (both.empty()){
            if(sbob <k && !bob.empty()){
                sbob++;
                res += bob .top();
                bob .pop();
            }if(salice <k && !alice.empty()){
                salice++;
                res += alice .top();
                alice.pop();
            }
        }else if (!both.empty() && salice<k && sbob <k){
            salice ++;
            sbob ++;
            res += both.top();
            both.pop();
        }
        i++;
        if (i>=n) break;
    }
    if (salice <k || sbob <k) non
    else cout << res <<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;     
    // cin >> test_case ; 
    while (test_case--)  solve() ;
}