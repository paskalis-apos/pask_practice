#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;

    vector<vector<bool>> dp(k + 1, vector<bool>(k + 1));

    dp[0][0] = true;

    for(int i = 0 ;i < n; i++) {
        int coin;
        cin >> coin;
        for(int ind1 = k; ind1 >= coin; ind1--) {
            for(int ind2 = k; ind2 >= 0; ind2--) {
                if(dp[ind1 - coin][ind2] == true) {
                    dp[ind1][ind2] = true;
                    dp[ind1][ind2 + coin] = true;
                }
            }
        }
    }

    vector<int> values;
    for(int i = 0 ;i <= k; i++) {
        if(dp[k][i]) {
            values.push_back(i);
        }
    }   

    cout << values.size() << endl;
    
    for(auto &x : values) {
        cout << x << " ";
    }
    cout << endl;
}