#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w'",stdout);
    int n , k;
    cin >> n >> k;

    vector<int> cowskills(n + 1);
    for(int i = 1 ;i <= n ;i++) {
        cin >> cowskills[i];
    }

    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++) {
        int maxvalue = 0;
        for(int counter = 0; counter < k; counter++) {
            maxvalue = max(maxvalue, cowskills[i - counter]);
            dp[i] = max(dp[i], maxvalue * (counter + 1) + dp[i - counter - 1]);
            if(i - counter == 1) {
                break;
            }
        }
    }

    cout << dp[n] << endl;
}