#include<bits/stdc++.h>
using namespace std;

int main( ) {
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;
    vector<pair<int,int>> rects(n);
    for(auto &x: rects) {
        cin >> x.first >> x.second;
    }

    vector<vector<int>> dp(w + 1, vector<int>(h + 1));

    for(int i = 0;i <= w; i++) {
        for(int j = 0;j <= h; j++) {
            dp[i][j] = i * j;
        }
    }

    for(auto &x: rects) {
        dp[x.first][x.second] = 0;
    }

    for(int i = 1; i <= w; i++) {
        for(int j =1; j<= h; j++) {
            for(int x = 1;x <= i; x++) {
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j]);
            }
            for(int y = 1; y <= j; y++) {
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y]);
            }
        }
    }

    cout << dp[w][h] << endl;
}