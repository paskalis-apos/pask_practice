#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 , s2;
    cin >> s1 >> s2;

    int size1 = s1.size();
    int size2 = s2.size();

    vector<vector<string>> dp(size1 + 1, vector<string>(size2 + 1));

    for(int i = 1 ;i <= size1; i++) {
        for(int j = 1; j <= size2; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i -1][j - 1] + s1[i -1];
            }
            else {
                if(dp[i -1][j].size() >= dp[i][j -1].size()) {
                    dp[i][j] = dp[i -1][j];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    cout << dp[size1][size2] << endl;
}