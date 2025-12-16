#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> occs(n + 1);
    int ind = 0;
    for(auto &x : v) {
        cin >> x;
        occs[x].push_back(ind);
        ind++;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int i = 0;i < n;i++ ){
        dp[i][i] = 1;
    }

    for(int d = 1; d < n; d++) {
        for(int i = 0;i + d < n; i++) {
            dp[i][i + d] = dp[i + 1][i + d] + 1;
            int el = v[i];
            for(auto &x : occs[el]) {
                if(i < x && x <= i + d) {
                    dp[i][i + d] = min(dp[i][i + d], dp[i + 1][x - 1] + dp[x + 1][i + d] + (i + 1 > x - 1));
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    

}