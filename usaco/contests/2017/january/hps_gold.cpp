#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n , k;
    cin >> n >> k;

    vector<int> v(n + 1);
    for(int i = 1 ; i <= n; i++) {
        char temp;
        cin >> temp;
        if(temp == 'P') {
            v[i] = 1;
        }
        else if(temp == 'H') {
            v[i] = 2;
        }
        else {
            v[i] = 3;
        }
    }

    vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(k + 1, vector<int>(4)));



    for(int i = 1; i<= n ;i++) {
        for(int j = 0; j <= k; j++) {
            for(int z = 1; z <= 3; z++) {
                dp[i][j][z] = dp[i -1][j][z];
                if(j > 0) {
                    for(int c = 1; c <= 3; c++) {
                        if(c != z) {
                            dp[i][j][z] = max(dp[i][j][z], dp[i - 1][j -1][c]);
                        }
                    }
                }
                if(z == v[i]) {
                    dp[i][j][z]++;
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0;i <= k; i++) {
        for(int j = 1; j <= 3; j++) {
            answer = max(answer, dp[n][i][j]);
        }
    }

    cout << answer << endl;
}