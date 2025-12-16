#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n , w;
    cin >> n >> w;

    vector<int> weights(n);
    vector<int> points(n);
    for(int i = 0 ;i <n ;i++) {
        cin >> weights[i] >> points[i];
    }

    vector<ll>dp(n * 1000 + 1, 1e15);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = n * 1000; j >= 0; j--) {
            if(dp[j] + weights[i] <= w ) {
                dp[j + points[i]] = min(dp[j + points[i]], dp[j] + weights[i]);
            }
        }
    }

    for(int i = n *1000 ;;i--) {
        if(dp[i] != 1e15) {
            cout << i;
            break;
        }
    }

}