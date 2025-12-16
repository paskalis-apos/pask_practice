#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;

    vector<int> heights(n);
    for(auto &x: heights) {
        cin >> x;
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1 ; j <= k; j++) {
            if(i + j <= n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(heights[i + j -1] - heights[i - 1]));
            }
        }
    }

    cout << dp[n];
}