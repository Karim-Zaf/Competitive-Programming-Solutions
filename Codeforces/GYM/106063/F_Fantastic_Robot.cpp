#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 

const int N = 100;
const int K = 10000;
int n, m, k;
char a[N][N];
string s[K];
bool vis[N][N][2 * K + 5];
vector<int> lnk[K];
int ax, ay, bx, by;

array<int, 3> get(int x, int y, int o, int ins) {
    char c = s[o][ins];
    int nx = x, ny = y;
    if(c == 'R'){
        ny++;
    }else if(c == 'L') {
        ny--;
    }else if(c == 'U'){
        nx--;
    }else {
        nx++;
    }
    int d = 1;
    if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '1')
        nx = x, ny = y, d = 0;

    return {nx, ny, d};
}

void solve() {
    cin >> n >> m;
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    cin >> ax >> ay >> bx >> by;

    cin >> k;
    int id = 0;
    for (int i = 0; i < k; i++){
        cin >> s[i];
        lnk[i].assign((int)s[i].size() + 1, 0);
        for(int j = 0; j <= (int)s[i].size(); j++)
            lnk[i][j] = id++;
    }

    deque<array<ll, 5>> q;
    for (int i = 0; i < k; i++)
        q.push_front({ax, ay, i, 0, 0});
        
    ll ans = 1e18;
    while (!q.empty()) {
        auto [x, y, o, ins, d] = q.front();
        q.pop_front();

        vis[x][y][lnk[o][ins]] = true;

        if (ins == (int)s[o].size()){
            if (x == bx && y == by)
                ans = min(ans, d);
            for (int i = 0; i < k; i++)
                if (!vis[x][y][lnk[i][0]]){
                    q.push_front({x, y, i, 0, d}); 
                    vis[x][y][lnk[i][0]] = true;
                }
        }else {
            auto [nx, ny, add] = get(x, y, o, ins);
            if (!vis[nx][ny][lnk[o][ins + 1]]){
                if(add > 0)
                    q.push_back({nx, ny, o, ins + 1, d + add});
                else
                    q.push_front({nx, ny, o, ins + 1, d + add});
                vis[nx][ny][lnk[o][ins + 1]] = true; 
            }
        }
    }

    cout << (ans == 1e18 ? -1 : ans) << endl;
}

int main()
{
    FAST

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}