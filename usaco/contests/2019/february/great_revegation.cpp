#include<bits/stdc++.h>
using namespace std;
int n , m;
vector<vector<pair<int,bool>>>adj;
vector<int> teams;
bool valid ;

bool bipart(int ind , int toteam) {
    if(teams[ind] != 0) {
        if(teams[ind] == toteam) {
            return true;
        }
        valid = false;
        return false;
    }
    teams[ind] = toteam;
    for(auto &x : adj[ind]) {
        int newteam;
        if(x.second == true) {
            newteam = toteam;
        }
        else {
            newteam = toteam % 2 + 1;
        }
        bipart(x.first, newteam);
    }

    return valid;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("revegetate.in","r", stdin);
    freopen("revegetate.out","w", stdout);
    cin >> n >> m;
    adj.resize(n);
    teams.resize(n);

    for(int i = 0 ;i < m ;i++) {
        char c;
        int a , b;
        cin >> c >> a >> b;
        a--;
        b--;
        if(c == 'S') {
            adj[a].push_back({b , true});
            adj[b].push_back({a, true});
        }
        else {
            adj[a].push_back({b , false});
            adj[b].push_back({a, false});
        }
    }
    int k = 0;

    for(int i = 0 ;i < n ;i++) {
        valid = true;
        if(teams[i] != 0) {
            continue;
        }
        if(bipart(i , 1)) {
            k++;
        }
        else {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1;
    for(int i = 0; i < k; i++) {
        cout << 0;
    }
    cout << endl;


}