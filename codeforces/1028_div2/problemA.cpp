#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pregcd(5001, vector<int>(5001));
int GCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    if(pregcd[a][b] == 0) {
        pregcd[a][b] = GCD(b, a % b);
    }
    return pregcd[a][b];
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    int finalgcd = v[0];
    for(int i = 1;i < n;i ++) {
        cin >> v[i];
        finalgcd = GCD(max(finalgcd,v[i]), min(v[i], finalgcd));
    }
    vector<vector<int>> dp(n + 1, vector<int>(5000 + 1, 1e9));
    int ready = 0;
    for(int i = 1; i <= n ;i++) {
        dp[i][v[i - 1]] = 0;
        if(v[i - 1] == finalgcd) {
            ready++;
        }
        for(int j = 1;j <= 5000 ;j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][GCD(max(j, v[i - 1]) , min(j, v[i - 1]))] = min(dp[i][GCD(max(j, v[i - 1]) , min(j, v[i - 1]))], dp[i - 1][j] + 1);
        }
    }

    int makesteps = dp[n][finalgcd];
    int ans = 0;
    if(ready > 0) {
        ans = n - ready;
    }
    else {
        ans = makesteps + n - 1;
    }

    cout << ans << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}