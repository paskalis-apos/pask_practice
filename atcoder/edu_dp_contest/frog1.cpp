#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for(auto &x : heights) {
        cin >> x;
    }

    vector<int>dp(n, INT_MAX);
    dp[0] = 0;

    for(int i = 0 ;i < n - 1;i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(heights[i] - heights[i + 1]));
        if(i + 2 < n) {
            dp[i + 2] = min(dp[i+2],dp[i] + abs(heights[i + 2] - heights[i]));
        }     
    }

    cout << dp[n - 1] << endl;
}