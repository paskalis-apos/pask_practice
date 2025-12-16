#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    vector<vector<int>> numocss(n + 1);
    for(int i = 1; i <= n;i++) {
        dp[i] = dp[i - 1];
        int num;
        cin >> num;
        numocss[num].push_back(i);
        if(numocss[num].size() >= num){ 
            int k = numocss[num].size() - num;
            dp[i] = max(dp[i], dp[numocss[num][k] - 1] + num);
        }
    }

    cout << dp[n] << endl;
    
}
int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}

