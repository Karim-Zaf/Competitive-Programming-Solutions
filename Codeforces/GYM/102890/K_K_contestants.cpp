/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
//#ifndef ONLINE_JUDGE
//#include "debug.cpp"
//#else
//#define kar(...)
//#endif
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

const ll N = 1e6 + 1 , MOD =1e9+7, mod=1e9+7, Q =2e5+4 ;

ll fact[N];


long long binpow(long long a, long long k){
    long long res = 1;
    while (k){
        if (k % 2)
            res = (res * a)%MOD;
        a = (a*a)%MOD ;
        k/=2 ;
    }
    return res ;
}

ll modinv(long long a){return binpow(a, MOD-2);}

ll divide(ll a, ll b){
    a %= MOD;
    b = modinv(b) % MOD;
    long long c = a*b;
    c%=MOD;
    return c;
}

void solve(){
    long long  A , B , C , K , c ;
    cin >> A >> B >> C >> K >> c ;
    if (K<=2){
        cout<<0<<"\n";
        return;
    }

    if (K-c<2){
        cout<<0<<"\n";
        return;
    }

    if (A+B+c < K){
        cout<<0<<"\n";
        return;
    }

    function <ll(ll,ll)> Comb =[](ll b, ll n){
        return divide(fact[n], fact[b]*fact[n-b]%MOD);
    };

    ll res = Comb(c,C);
//    res = (res * (A+B))%MOD;
    ll ans1 = Comb(K-c, A+B);

    if (B>=(K-c)){
        ans1 = (((ans1 - Comb(K-c, B))%MOD)+MOD)%MOD;
    }

    if (A>=(K-c)){
        ans1 = (((ans1 - Comb(K-c, A))%MOD)+MOD)%MOD;
    }

    res = (res * ans1)%MOD;
    cout << res << endl;
}


void preprocess(){
    fact[0]= 1 ;
    for (int i= 1 ;i<N ;i++){
        fact[i]= fact[i-1]*i;
        fact[i]%=MOD ;
    }
}

int32_t main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(false) ;cin.tie(NULL) ; srand(time(0)) ; int test_case=1;
    cin >> test_case ;
    preprocess ();
    while (test_case--)  solve() ;
}
