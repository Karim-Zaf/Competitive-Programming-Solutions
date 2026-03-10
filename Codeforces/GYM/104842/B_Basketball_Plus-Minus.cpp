#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

void solve(){
    set<string> players[3];
    vector<string> team_name(3);
    map<string, int> mp, score[3];
    vector<pair<string, string>> vec;
    for (int id = 1; id <= 2; id++){
        cin >> team_name[id];
        mp[team_name[id]] = id;
        for (int i = 0; i < 5; i++){
            string s;
            cin >> s;
            vec.push_back({s, team_name[id]});
            score[id][s] = 0;
            players[id].insert(s);
        }
    }
    int Q;
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        string s, name;
        cin >> s >> name >> s;
        if (s == "scored"){
            int x;
            cin >> x;
            int id = mp[name];
            for (string player : players[id]) score[id][player] += x;
            for (string player : players[3 - id]) score[3 - id][player] -= x;
        }
        else{
            string p1, p2;
            cin >> p1 >> s >> p2;
            int id = mp[name];
            if (!score[id].count(p2)){
                score[id][p2] = 0;
                vec.push_back({p2, name});
            }
            players[id].erase(p1);
            players[id].insert(p2);
        }
    }
    for (auto [player, team] : vec){
        int id = mp[team];
        int s = score[id][player];
        cout << player << " (" << team_name[id] << ") ";
        if (s > 0) cout << "+" << s << endl;
        else if (s < 0) cout << "-" << abs(s) << endl;
        else cout << s << endl;
    }
}

int main(){
    FAST
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}