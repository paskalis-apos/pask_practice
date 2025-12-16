#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod ll(1e9 + 7);

vector<vector<int>> adj;
vector<ll> dp[3];
int n ,k;

void dfs(int cur, int par) {
    for(auto &x : adj[cur]){
        if(x == par) {
            continue;
        }
        dfs(x , cur);
        for(int i = 0 ;i < 3 ;i++) {
            ll ways = 0;
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    ways += dp[j][x];
                    ways %= mod;
                }
            }
            dp[i][cur] *= ways;
            dp[i][cur] %= mod;
        }
    }
}

int main() {\
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);
    cin >> n >> k;
    adj.resize(n);
    dp[0].resize(n, 1);
    dp[1].resize(n, 1);
    dp[2].resize(n, 1);

    for(int i = 0;i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0;i < k; i++) {
        int b , c;
        cin >> b >> c;
        b--;
        c--;
        for(int j = 0 ;j < 3; j++) {
            if(j != c) {
                dp[j][b] = 0;
            }
        }
    }

    dfs(0 , -1);
    ll answer = dp[0][0] + dp[1][0] + dp[2][0];
    answer %= mod;
    cout << answer << endl;
}

