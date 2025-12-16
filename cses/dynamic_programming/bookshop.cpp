#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(auto &y : prices) {
        cin >>y;
    }
    for(auto &y : pages){
        cin >> y;
    }

    vector<vector<int>>dp(n + 1, vector<int>(x + 1));


    for(int i = 1 ;i <= n; i++) {
        int curprice = prices[i - 1];
        int curpages = pages[i - 1];

        for(int j = 1 ; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];

            if(j >= curprice) {
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - curprice] + curpages);
            }
        }
    }

    cout << dp[n][x];

}