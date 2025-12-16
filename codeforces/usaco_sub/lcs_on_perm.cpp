#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> posA(n + 1);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        posA[num] = i;
    }

    vector<int> Aind(n);
    for(int i = 0;i < n; i++) {
        int num;
        cin >> num;
        Aind[i] = posA[num];
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = -INT_MAX;

    for(int i = 0;i < n;i++) {
        int ind = lower_bound(dp.begin(), dp.end(), Aind[i]) - dp.begin();
        dp[ind] = Aind[i];
    }

    int ans = 0;
    for(int i = 0;i <= n;i++) {
        if(dp[i] != INT_MAX){
            ans = i;
        }
    }

    cout << ans << endl;
}