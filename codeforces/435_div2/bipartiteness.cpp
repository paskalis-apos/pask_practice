#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<vector<ll>> adj;
vector<ll>team;
ll ones = 0, twos = 0;

void find_teams(ll ind, ll mustteam) {
    if(team[ind] != 0) {
        return;
    }
    team[ind] = mustteam;
    if(mustteam == 1){
        ones++;
    }
    else {
        twos++;
    }
    for(auto &x : adj[ind]) {
        if(mustteam == 1){
            find_teams(x , 2);
        }
        else {
            find_teams(x, 1);
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    team.resize(n);
    
    for(ll i = 0 ;i < n - 1;i++) {
        ll a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_teams(0 , 1);
    
    ll answer = ones * twos - (n - 1);

    cout << answer << endl;


}