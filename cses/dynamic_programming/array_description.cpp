#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod int(1e9 + 7);

int main() {
    ll n , m;
    cin >> n >> m;

    vector<ll> arr(n);
    for(auto &x : arr) {
        cin >> x;
    }

    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2));
    dp[0][0] = 1;
    
    for(int i = 1 ;i <= n ; i++) {
        for(int j = 1; j <= m ; j++) {
            if(i == 1) {
                if(arr[i - 1] == 0 || arr[i - 1] == j) {
                    dp[i][j] = 1;
                }
                continue;
            }
            if(arr[i - 1] == 0 || arr[i - 1] == j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i -1][j] + dp[i -1][j + 1];
            }
            dp[i][j] %= mod;
        }
    }

    ll answer = 0;
    for(auto &x : dp[n]) {
        answer += x;
        answer %= mod;
    }

    cout << answer << endl;
}