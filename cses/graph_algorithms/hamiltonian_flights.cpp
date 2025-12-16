#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod ll(1e9 + 7);


int n , m;
vector<vector<int>> comefrom;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    comefrom.resize(n );
    vector<vector<ll>> dp(1 << n, vector<ll>(n ));
    for(int i = 0 ;i < m;i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        comefrom[b].push_back(a);
    }

    dp[1][0] = 1;
    for(int i = 2; i < (1 << n); i++) {
        if((i & (1 << 0)) == 0) {
            continue;
        }
        if((i & (i << (n -1))) == 1 && (i != (1 << n) - 1)) {
            continue;
        }

        for(int end = 0; end < n; end++) {
            if((i & (1 << end)) == 0) {
                continue;
            }
            int prev = i - (1 << end);
            for(int j : comefrom[end]) {
                if((prev & ((1 << j)))) {
                    dp[i][end] += dp[prev][j];
                    dp[i][end] %= mod;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}