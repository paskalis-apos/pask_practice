#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define TOMOD 998244353


int main() {
    ll q , k;
    cin >> q >> k;
    vector<vector<ll>>dp(q + 1, vector<ll>(k + 1));
    dp[0][0] = 1;

    for(int i = 1; i <= q; i++) {
        string c;
        cin >> c;
        ll num;
        cin >> num;
        for(int j = 0; j<= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - num >= 0) {
                if(c == "+") {
                    dp[i][j] += dp[i -1][j - num];
                }
                else {
                    dp[i][j] -= dp[i][j - num];
                }
            }
            dp[i][j] %= TOMOD;
        }
        cout << (dp[i][k] % TOMOD + TOMOD) % TOMOD << endl;;
    }
}

