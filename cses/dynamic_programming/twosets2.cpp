#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod int(2 * (1e9 + 7));
#define maxsum int(300 * 250 + 1)

int main() {
    int n;
    cin >> n;

    vector<vector<ll>>dp(500 + 1, vector<ll>(maxsum));
    dp[0][0] = 1;
    for(int i = 1; i <= 500; i++) {
        for(int j = 0; j <= maxsum; j++) {
            dp[i][j] = dp[i- 1][j];
            if(j - i >= 0){
                dp[i][j] += dp[i - 1][j - i];
            }
            dp[i][j] %= mod;
        }
    }

    int ans = dp[n][n * (n + 1) / 4] ;
    ans /= 2;
    if((n * (n + 1)) % 4 != 0) {
        ans = 0;
    }
    printf("%d\n", ans);

    return 0;
}