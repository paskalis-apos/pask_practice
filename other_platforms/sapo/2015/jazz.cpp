#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int size = s.size();

    vector<vector<int>> dp(size + 2, vector<int>(size + 2));

    for(int i = 0 ;i <= size; i++) {
        for(int j = 0; j < size - i; j++) {
            dp[j][i + j] = dp[j + 1][i + j] + 1;
            for(int k = j + 1; k <= i + j ; k++) {
                if(s[j] == s[k]) {
                    dp[j][i + j] = min(dp[j][i + j], dp[j + 1][k - 1] + dp[k + 1][i + j]);
                }
            }
        }
    }

    cout << dp[0][size - 1] << endl;
} 