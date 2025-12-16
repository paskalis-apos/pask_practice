#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<ll>> adj;

int main() {
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    ll n , m , c;
    cin >> n >> m >> c;
    adj.resize(n);

    vector<ll> moonies(n);
    for(auto &x : moonies) {
        cin >> x;
    }

    for(int i = 0 ; i < m ;i++) {
        ll a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    vector<vector<ll>> dp(1000 , vector<ll>(n));
    for(int i = 0 ;i < 1000 ;i++) {
        for(int j = 0 ; j < n; j++) {
            dp[i][j] = -1e12;
        }
    }
    dp[0][0] = 0;
    ll answer = 0;

    for(int j = 1; j < 1000 ;j++) {
        for(int i = 0 ;i < n ;i++) {
            for(auto &x : adj[i]) {
                dp[j][x] = max(dp[j][x], dp[j - 1][i]+ moonies[x]);
            }
        }   
        answer = max(answer, dp[j][0] - c * j * j);
    }

    cout << answer << endl;

    

}