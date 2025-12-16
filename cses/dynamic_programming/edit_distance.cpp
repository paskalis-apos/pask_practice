#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 , s2;
    cin >> s1 >> s2;
    int size1 = s1.size();
    int size2 = s2.size();

    vector<vector<int>> dp(size1 + 1,vector<int>(size2 + 1, 1e9));
    dp[0][0] = 0;

    for (int j = 0; j <= size2; j++) {
        dp[0][j] = j;
    }
    for (int i = 0; i <= size1; i++) {
        dp[i][0] = i;
    }

    for(int i = 1 ;i <= size1; i++) {
        for(int j = 1; j <= size2; j++) {
            dp[i][j] = min(dp[i][j], dp[i -1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j] ,dp[i -1][j -1] + (s1[i -1] != s2[j - 1]));
        }
    }

    cout << dp[size1][size2];
    cout << endl;
}